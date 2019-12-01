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

#define MAX_FACTORIAL 12
#define EPSILON 1E-6
int factorials[] = {1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880, 3628800, 39916800, 479001600};

int main(){
	io;
	int m,n,t;
	c3(m,n,t);
	bool ac;
	switch(t){
		case 1:{
			ac = (n>MAX_FACTORIAL||factorials[n]>m)?0:1;
			break;
		}
		case 2:{
			ac = n<=log2(m)+EPSILON;
			break;
		}
		case 3:{
			ac = n<=pow(m,0.25)+EPSILON;
			break;
		}
		case 4:{
			ac = n<=pow(m,0.333333333333333333333333333333333333333333333333333333)+EPSILON;
			break;
		}
		case 5:{
			ac = n<=pow(m,0.5)+EPSILON;
			break;
		}
		case 6:{
			ac = n*log2(n)<=m+EPSILON;
			break;
		}
		case 7:{
			ac = n<=m;
			break;
		}
	}
	printf(ac?"AC":"TLE");
	return 0;
}
