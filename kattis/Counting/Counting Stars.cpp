#include <map>
#include <set>
#include <queue>
#include <cmath>
#include <vector>
#include <cstdio>
#include <bitset>
#include <cstring>
#include <cstdlib>
#include <complex>
#include <iostream>
#include <algorithm>
#include <math.h>
#include <list>
#include <stack>
#include <iterator>
#include <complex>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
using namespace std;

#define io ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define fora(i,a,b) for(int i=a;i<b;i++)
#define fors(i,a,b) for(int i=a-1;i>=b;i--)
#define men(a) menset(a,0,sizeof(a))
#define sc(x) scanf("%d",&x)
#define scll(x) scanf("%lld",&x)
#define c1(a) cin>>a
#define c2(a,b) cin>>a>>b
#define c3(a,b,c) cin>>a>>b>>c
#define pb push_back
#define ff first
#define ss second
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pi;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<bool> vb;
typedef vector<vector<int> > vvi;
typedef map<int,int> mi;
typedef map<long,long> mll;

void lap(int sky[101][101],int i,int j,int n,int m){
	sky[i][j]=0;
	if(sky[i][j+1]&&j+1<m)lap(sky,i,j+1,n,m);
	if(sky[i+1][j]&&i+1<n)lap(sky,i+1,j,n,m);
	if(sky[i-1][j]&&i>0)lap(sky,i-1,j,n,m);
	if(sky[i][j-1]&&j>0)lap(sky,i,j-1,n,m);
}
int main(){
	int n,m,k=1;
	while(cin>>n>>m){
		int sky[101][101]={};
		cin.ignore();
		fora(i,0,n){
			string x;
			cin>>x;
			fora(j,0,m){
				if(x[j]=='#')
					sky[i][j]=0;
				else
					sky[i][j]=1;
			}
		}
		int count=0;
		fora(i,0,n)
			fora(j,0,m)
				if(sky[i][j]){
					count++;
					lap(sky,i,j,n,m);
				}
		cout<<"Case "<<k<<": "<<count<<endl;
		k++;
	}
	return 0;
}
