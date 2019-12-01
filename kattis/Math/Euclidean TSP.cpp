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
#include <ctype.h>
#include <functional>
#include <stack>
#include <iterator>
#include <complex>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
//#include <unordered_map>
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
#define M_PI 3.14159265358979323846
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

#define RES_PHI (2 - ((1.0 + sqrt(5)) / 2.0))
#define EPSILON 1e-7
ld gss(function<ld(ld)> f, ld leftbound, ld rightbound) {
	ld lb = leftbound, rb = rightbound, mlb = lb + RES_PHI * (rb - lb), mrb = rb + RES_PHI * (lb - rb);
	ld lbv = f(lb), rbv = f(rb), mlbv = f(mlb), mrbv = f(mrb);

	while (rb - lb >= EPSILON || abs(rbv - lbv) >= EPSILON) {
		if (mlbv < mrbv) { // > to maximize
			rb = mrb;  rbv = mrbv;
			mrb = mlb;  mrbv = mlbv;
			mlb = lb + RES_PHI * (rb - lb);
			mlbv = f(mlb);
		}
		else {
			lb = mlb;  lbv = mlbv;
			mlb = mrb;  mlbv = mrbv;
			mrb = rb + RES_PHI * (lb - rb);
			mrbv = f(mrb);
		}
	}

	if (lbv < mlbv && lbv < mrbv && lbv < rbv) return lb;
	if (mlbv < mrbv && mlbv < rbv) return mlb;
	if (mrbv < rbv) return mrb;
	return rb;
}
int main(){
	io;
	int n;
	ld p, s, v;
	cin >> n >> p >> s >> v;

	auto f = [=](ld c){return (s * (1 + 1 / c) / v) + (n * pow((log(n) / log(2)), c*sqrt(2)) / (p * 1e9)); };
	ld f1 = f(0), f2 = f(1), va = 1;
	while (f1 > f2) {
		va *= 2;
		f1 = f2;
		f2 = f(va);
	}
	
	double c = (double)gss(f, 0, va);
	double t = (double)f(c);
	printf("%.7f %.7f \n", t, c);
	return 0;
}
