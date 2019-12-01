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
#define INF 1000000000000000000
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
ll n,k;
vector<pair<ll,ll>> v(12);
vector<pair<ll,ll>> p;
map<pair<ll,ll>,bool> m;
vector<int> q;
ll res=1e9;
ll tinh(){
	ll total=0;
	fora(i,0,n){
		ll minx=1e9;
		fora(j,0,q.size()){
//			cout<<i<<' '<<q[j]<<':'<<endl;
			minx=min(minx,(abs(v[i].ff-p[q[j]].ff)+abs(v[i].ss-p[q[j]].ss)));
//			cout<<v[i].ff<<'-'<<v[q[j]].ff<<'+'<<v[i].ss<<'-'<<v[q[j]].ss<<'='<<minx<<endl;
		}
//		cout<<endl;
		total+=minx;
		if(total>res)
			return total;
	}
//	cout<<total<<endl;
	return total;
}
void backtracking(int x){
	q.pb(x);
	if(q.size()==k){
		res=min(res,tinh());
//		cout<<res<<endl;
		q.pop_back();
		return;
	}
	fora(i,x+1,p.size()){
		backtracking(i);
	}
	q.pop_back();
}
int main(){
	io;
	solve();
	return 0;
}

void solve(){
	cin>>n>>k;
	fora(i,0,n)
		cin>>v[i].ff>>v[i].ss;
	if(n==k){
		cout<<0;
		return;
	}
	fora(i,0,n){
		if(!m[v[i]]){
			p.pb(v[i]);
			m[v[i]]=true;
		}
		fora(j,i+1,n){
			if(v[i].ff==v[j].ff||v[i].ss==v[j].ss)
				continue;
			pair<ll,ll> temp;
			temp.ff=v[i].ff;
			temp.ss=v[j].ss;
			if(!m[temp]){
				p.pb({v[i].ff,v[j].ss});
				m[temp]=true;
			}
			temp.ff=v[j].ff;
			temp.ss=v[i].ss;
			if(!m[temp]){
				p.pb({v[j].ff,v[i].ss});
				m[temp]=true;
			}
		}
	}
	sort(all(p));
//	res=(abs(p[0].ff-p[p.size()-1].ff)+abs(p[0].ss-p[p.size()-1].ss))*k;
//	fora(i,0,p.size())
//		cout<<p[i].ff<<' '<<p[i].ss<<endl;
	fora(i,0,p.size()){
		backtracking(i);
	}
	cout<<res;
}
/*
5 3
0 4
4 0
4 4
0 0
2 2
*/
