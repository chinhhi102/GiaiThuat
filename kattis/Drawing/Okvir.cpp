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
#define sc(x) scanf("%d",&x);
#define scll(x) scanf("%lld",&x);
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
	int m,n;
	string dot_hash=".#";
	scanf("%d%d",&n,&m);
	string text[n];
	int u,l,r,d;
	scanf("%d%d%d%d",&u,&l,&r,&d);
	fflush(stdin);
	fora(i,0,n)cin>>text[i];
//	fora(i,0,n){fora(j,0,m)printf("%c",text[i][j]);printf("\n");}
	int a=n+u+d,b=m+r+l;
	fora(i,0,a){
		fora(j,0,b){
			if(i-u>=0&&i-u<n)
				if(j-l>=0&&j-l<m)printf("%c",text[i-u][j-l]);
				else printf("%c",i%2?dot_hash[j%2]:dot_hash[(j+1)%2]);
			else printf("%c",i%2?dot_hash[j%2]:dot_hash[(j+1)%2]);
		}
		printf("\n");
	}
	return 0;
}
