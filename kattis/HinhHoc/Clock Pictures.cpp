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
	int n;
	sc(n);
	vector<double> clock_1;
	vector<double> clock_2;
	fora(i,0,n){
		int degree;
		sc(degree);
		clock_1.pb(i==0?degree:((abs(clock_1[i-1]-degree)>180000)?abs(180000-abs(clock_1[i-1]-degree)):abs(clock_1[i-1]-degree))/double(360000.0));
	}
	fora(i,0,n){
		int degree;
		sc(degree);
		clock_2.pb(i==0?degree:((abs(clock_2[i-1]-degree)>180000)?abs(180000-abs(clock_2[i-1]-degree)):abs(clock_2[i-1]-degree))/double(360000.0));
	}
//	fora(i,0,n)printf("%lf %lf\n",clock_1[i],clock_2[i]);
	bool res=1;
	fora(i,1,n){
		if(clock_2[i]!=clock_1[i]){
			res=0;
			break;
		}
	}
	printf(res?"possible":"impossible");
	return 0;
}
