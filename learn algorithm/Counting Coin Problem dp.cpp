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

#define INF 10000000
vi coins;

void inp(int &x){
	int n,tmp;
	printf("number of coins : ");
	sc(n);
	printf("value coin : ");
	fora(i,0,n){
		sc(tmp);
		coins.pb(tmp);
	}
	printf("sum of money x is : ");
	sc(x);
}

ll solve(int x){
	vll count;
	count.pb(1);
	fora(i,1,x+1){
		count.pb(0);
		fora(c,0,coins.size()){
			if(i-coins[c]>=0)
				count[i]+=count[i-coins[c]];
		}
	}
	return count[x];
}

int main(){
	vi coins;
	int x;
	inp(x);
	printf("total number of the ways to product a sum x is %lld",solve(x));
	return 0;
}