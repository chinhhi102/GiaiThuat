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
vector<pair<int, int>> ant;

int sol(int idx) {
	int opp=0;
	if(ant[idx].second){
		fora(i,idx+1,ant.size())
			if(!ant[i].second)
				opp++;
		return idx+opp;
	}else{
		fors(i,idx,0)
			if(ant[i].second)
				opp++;
		return idx-opp;
	}
}

int main(){
	io;
	solve();
	return 0;
}

void solve(){
	int l,a;
	while(cin>>l>>a){
		ant.resize(a);
		fora(i,0,a){
			char c;
    		cin>>ant[i].first>>c;
    		ant[i].second=(c=='R')?1:0;
		}
		sort(ant.begin(),ant.end());
		int maxT=0;
		fora(i,0,a){
			if(ant[i].second)
				maxT=max(maxT,l-ant[i].first);
    		else
				maxT=max(maxT,ant[i].first);
		}
		vector<int> ans;
		fora(i,0,a){
			if(ant[i].second&&l-ant[i].first==maxT)
				ans.push_back(sol(i));
    		else if(!ant[i].second&&ant[i].first==maxT)
				ans.push_back(sol(i));
		}
		sort(ans.begin(), ans.end());
		cout<<"The last ant will fall down in "<<maxT<<" seconds - started at "<<ant[ans[0]].first;
		if(ans.size()==2)
			cout<<" and "<<ant[ans[1]].first;
			cout<<"."<<endl;
	}
}
