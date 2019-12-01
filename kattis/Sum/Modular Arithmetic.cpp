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
ll mod(ll a, ll b){
	if(a%b<0) return (a%b+b);
	return (a%b);
}

ll x,y,q;
void ext(ll a, ll b){
	if(a==0){
		x=0;y=1;q=b;
		return;
	}
	if(b==0){
		x=1;y=0;q=a;
		return;
	}
	ll r = mod(a,b);
	ll q = (a-r)/b;
	ext(b,mod(a,b));
	ll temp = x;
	x = y;
	y = temp - q*y;
}

ll mod_add(ll a, ll b, ll n){
	if(a+b>=n) return a+b-n;
	else return a+b;
}

ll mod_minus(ll a, ll b, ll n){
	if(a<b) return a+n-b;
	else return a-b;
}

ll mod_multi(ll a, ll b,ll n){
	ll res = 0;
	while(b){
		if(b%2==1) res=mod_add(res,a,n);
		b/=2;
		a=mod_add(a,a,n);
	}
	return res;
}

ll mod_divide(ll a, ll b, ll n){
	q=0;
	ext(b,n);
	if(b*x+n*y==1){
		x=mod(x,n);
		return mod_multi(a,x,n);
	}
	else return -1;
}
int main(){
	io;
	solve();
	return 0;
}

void solve(){
	int n,m;
	while(cin>>n>>m && n && m){
		int a,b;
		char op;
		while(m--){
			cin>>a>>op>>b;
			if(op=='+') cout<<mod_add(a,b,n)<<endl;
			else if(op=='-') cout<<mod_minus(a,b,n)<<endl;
			else if(op=='*') cout<<mod_multi(a,b,n)<<endl;
			else if(op=='/') cout<<mod_divide(a,b,n)<<endl;
		}
	}
}
