#ifndef competitive_programming_H
#define competitive_programming_H
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
#include <iomanip>
#include <list>
#include <tuple>
#include <ctype.h>
#include <stack>
#include <iterator>
#include <complex>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <functional>
#include <time.h>
#include <unordered_map>
#include <unordered_set>
#include <functional>
using namespace std;

#define io ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
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
#define all(x) (x).begin(), (x).end()
#define M_PI 3.14159265358979323846
#define fix(x) cout<<fixed<<setprecision(x)
#define UNIQUE(c) (c).resize(unique(all(c))-(c).begin())
#define debug freopen("D:\\baiTapLapTrinh\\UVa\\out.txt","w",stdout);
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
#endif
void solve();
int n;
bool mat[100+3][100+3];
bool vis[100+3];
int main(){
	io;
	solve();
	return 0;
}

void DFS(int x,int y){
	if(x==y)return;
	vis[x]=1;
	fora(i,0,n){
		if(mat[x][i]&&!vis[i]){
			DFS(i,y);
		}
	}
}

void solve(){
//	debug;
	int TC;
	scanf("%d",&TC);TC++;
	fora(cases,1,TC){
		scanf("%d",&n);
		memset(mat,0,sizeof mat);
		fora(i,0,n)
			fora(j,0,n)
				scanf("%d",&mat[i][j]);
		bool output[103][103]={};
		bool firstVis[103];
		memset(vis,0,sizeof vis);
		DFS(0,-1);		
		fora(i,0,103)
			firstVis[i]=vis[i];
		fora(i,0,n){
			memset(vis,0,sizeof vis);
			DFS(0,i);
			fora(j,0,n)
				output[i][j]=(firstVis[j]&&!vis[j]);
			output[i][i]=firstVis[i];
		}
		printf("Case %d:\n",cases);
		printf("+");fora(i,0,n*2-1)printf("-");printf("+\n");
		fora(i,0,n){
			printf("|");fora(j,0,n)printf("%c|",output[i][j]?'Y':'N');printf("\n");
			printf("+");fora(i,0,n*2-1)printf("-");printf("+\n");
		}
	}
}
