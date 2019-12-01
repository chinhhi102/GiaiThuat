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
#define for(i,a,b) for(int i=a;i<=b;i++)
#define fors(i,a,b) for(int i=a;i>=b;i--)
#define men(a) menset(a,0,sizeof(a))
#define sc(x) scanf("%d",&x);
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
	int n,j(1);sc(n);
	while(n--&&j++){
		int ns,res(0);sc(ns);
		int a[ns],b[ns];
		for(i,0,ns-1)sc(a[i]);
		for(i,0,ns-1)sc(b[i]);
		sort(a,a+ns);
		sort(b,b+ns);
		for(i,0,ns-1)res+=a[ns-i-1]*b[i];
		printf("Case #%d: %d\n",j-1,res);
	}
	return 0;
}
