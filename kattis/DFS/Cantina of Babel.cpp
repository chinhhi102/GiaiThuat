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
#include <unordered_map>
#include <unordered_set>
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
void dfs1(unordered_map<string,pair<int,vector<string> > >& m,unordered_set<string>& vis,stack<string>& r,string curr){
	if(vis.count(curr)>0)
		return;
	vis.insert(curr);
	for(vector<string>::iterator i=m[curr].ss.begin();i!=m[curr].ss.end();i++){
		dfs1(m,vis,r,*i);
	}
	r.push(curr);
}
void dfs2(unordered_map<string,vector<string> >& m,unordered_set<string>& vis,vector<string>& comp,string curr){
	if(vis.count(curr)>0)
		return;
	vis.insert(curr);
	comp.pb(curr);
	for(vector<string>::iterator i=m[curr].begin();i!=m[curr].end();i++)
		dfs2(m,vis,comp,*i);
}
int main(){
	io;
	int n;
	cin>>n;
	unordered_map<string,pair<int,vector<string> > > m1;
	unordered_map<string,vector<string> > m2;
	unordered_set<string> names;
	fora(i,0,n){
		string name,lang,s;
		cin>>name>>lang;
		names.insert(lang);
		m1[lang].ff++;
		while(cin.peek()!='\n'){
			cin>>s;
			m1[lang].ss.pb(s);
			m2[s].pb(lang);
		}
	}
	stack<string> r;
	unordered_set<string> vis;
	for(unordered_set<string>::iterator i=names.begin();i!=names.end();i++){
		if(vis.count(*i)>0)
			continue;
		dfs1(m1,vis,r,(*i));
	}
	vis.clear();
	int best=0;
	while(!r.empty()){
		string curr=r.top();
		r.pop();
		if(vis.count(curr)>0)
			continue;
		vector<string> comp;
		dfs2(m2,vis,comp,curr);
		int here=0;
		fora(i,0,comp.size()){
			here+=m1[comp[i]].ff;
		}
		best=max(best,here);
	}
	cout<<n-best<<endl;
	return 0;
}
