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

const int UP=1,DOWN=-1;

int main(){
	int N,M,up,down;
    cin >> N;
    while (N--){
        cin>>M;
		int d[M+1];
		int a[41][1001];
		memset(a,-1,sizeof(a));
		int dir[41][1001]={};
		fora(i,1,M+1)
			cin>>d[i];
		a[0][0]=0;
		fora(i,1,M+1){
			fora(j,0,1001-d[i]){
				up=j+d[i];
				down=j-d[i];
				if(down>=0){
					if(a[i-1][up]!=-1&&a[i-1][down]!=-1){
						a[i][j]=min(a[i-1][up],max(j,a[i-1][down]));
						dir[i][j]=a[i-1][up]>max(j,a[i-1][down])?UP:DOWN;
					}else if(a[i-1][up]!=-1){
						a[i][j]=a[i-1][up];
						dir[i][j]=DOWN;
					}else if(a[i-1][down]!=-1){
						a[i][j]=max(j,a[i-1][down]);
						dir[i][j]=UP;
					}
				}else if(a[i-1][up]!=-1){
					a[i][j]=a[i-1][up];
					dir[i][j]=DOWN;
				}
			}
		}
		int sol[M+1]={};
		int pos=0;
		fors(i,M+1,1){
			sol[i]=dir[i][pos];
			pos-=dir[i][pos]*d[i];
		}
		if(a[M][0]!=-1){
			fora(i,1,M+1)
				cout<<(sol[i]==UP?"U":"D");
			cout<<endl;
		}else
			cout<<"IMPOSSIBLE\n";
	}
	return 0;
}
