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
int M,C,price[25][25];
int memo[210][25];
int shop(int money,int g);//TOP-DOWN

void solve2();

int main(){
	io;
//	solve();//top - down
	solve2();//botton - up
	return 0;
}

int shop(int money,int g){
	if(money<0)
		return -1000000000;
	if(g==C)
		return M-money;
	if(memo[money][g]!=-1)
		return memo[money][g];
	int ans=-1;
	fora(model,1,price[g][0]+1){
		ans=max(ans,shop(money-price[g][model],g+1));
	}
	return memo[money][g]=ans;
}

void solve(){
	int N;
	scanf("%d",&N);
	while(N--){
		scanf("%d %d",&M,&C);
		fora(i,0,C){
			scanf("%d",&price[i][0]);
			fora(j,1,price[i][0]+1)
				scanf("%d",&price[i][j]);
		}
		memset(memo,-1,sizeof memo);
		int score=shop(M,0);
		if(score<0)
			printf("no solution\n");
		else
			printf("%d\n",score);
	}
}

void solve2(){
	int N;
//	freopen("D:\\baiTapLapTrinh\\UVa\\out.txt","w",stdout);
	bool reachable[25][210];
	scanf("%d",&N);
	while(N--){
		scanf("%d %d",&M,&C);
		fora(i,0,C){
			scanf("%d",&price[i][0]);
			fora(j,1,price[i][0]+1)
				scanf("%d",&price[i][j]);
		}
		memset(reachable,0,sizeof reachable);
		fora(i,1,price[0][0]+1)
			if(M-price[0][i]>=0)
				reachable[0][M-price[0][i]]=1;
		fora(g,1,C)
			fora(money,0,M)
				if(reachable[g-1][money])
					fora(k,1,price[g][0]+1)
						if(money-price[g][k]>=0)
							reachable[g][money-price[g][k]]=1;
		int money;
		for(money=0;money<=M&&!reachable[C-1][money];money++);
		if(money==M+1)
			printf("no solution\n");
		else
			printf("%d\n",M-money);
	}
}
