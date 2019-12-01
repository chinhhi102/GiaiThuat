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

int main(){
	io;
	int n,m;
	while(cin>>n>>m){
		int N=n,M=m;
		
		int d=0;
		if(!(n+m))break;
		int j=0;
		map<int,int> dataN;
		while(n>1){
			j++;
			if(n%2){
				n=n*3+1;
			}else{
				n/=2;
			}
			if(!dataN[n])
				dataN[n]=j;
		}
		j=0;
		if(!dataN[m]){
			while(m>1){
				j++;
				if(m%2)
					m=m*3+1;
				else
					m/=2;
				if(dataN[m])
					break;
			}
		}
		cout<<N<<" needs "<<dataN[m]<<" steps, "<<M<<" needs "<<j<<" steps, they meet at "<<m<<endl;
		dataN.clear();
	}
	return 0;
}
