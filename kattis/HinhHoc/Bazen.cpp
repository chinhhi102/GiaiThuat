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
//#include <tuple>
#include <ctype.h>
#include <stack>
#include <iterator>
#include <complex>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <functional>
#include <time.h>
//#include <unordered_map>
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

void solve();
double t=31250.0;
int main(){
	io;
	solve();
	return 0;
}

void solve(){
	int x,y;
	cin>>x>>y;
	double anx,any;
	if(x!=0&&y!=0){
		if(y>=125){
			anx=250-t/y;
			any=0;
		}else{
			anx=0;
			any=250-t/x;
		}
	}else{
		if(x==0&&y==0){
			anx=125.0;
			any=125.0;
		}else if(x==0&&y!=0){
			if(y>=125){
				anx=t/y;
				any=0;
			}else{
				anx=t/(250-y);
				any=125-(anx*y/250);
			}
		}else{
			if(x<125){
				any=t/(250-x);
				anx=125-(any*x/250);
			}else{
				anx=0;
				any=t/x;
			}
		}
	}
	fix(2)<<anx<<" "<<any;
}
