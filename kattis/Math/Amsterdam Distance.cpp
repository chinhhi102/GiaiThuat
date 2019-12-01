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
#include <cmath>
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

#define pi  3.14159265

int main(){
	double m,n,ax,ay,bx,by;
	double r;
	scanf("%lf%lf%lf%lf%lf%lf%lf",&m,&n,&r,&ax,&ay,&bx,&by);
	double khoang_cach=abs(ay-by);
	double d=r/n*khoang_cach;
	double duong_tron_nho=min(ay,by);
	double cung_duong_di=r/n*duong_tron_nho;
	double so_do_1_cung=abs(ax-bx)/m;
	double L=so_do_1_cung*cung_duong_di*pi;
	double res=L+d;
	printf("%.14lf",min(ay*r/n+by*r/n,res));
	return 0;
}
