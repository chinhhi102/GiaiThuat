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
typedef pair<int,int> edg;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<bool> vb;
typedef vector<vector<int> > vvi;
typedef map<int,int> mi;
typedef map<long,long> mll;

int link[100010];
int size[100010];
map<int,bool> m[100010];
//vector<int> color(1,0);
void solve();
bool same(int a,int b);
int find(int x);
void unite(int a,int b);
bool same(int a,int b){
	return find(a)==find(b);
}
int find(int x){
	while(x!=link[x])x=link[x];
	return x;
}
void unite(int a,int b){
	a=find(a);
	b=find(b);
	if(size[a]<size[b])
		swap(a,b);
	size[a]+=size[b];
	link[b]=a;
	if(m[a][]){
		
	}else
		m[b]+=m[a];
}
int main(){
	io;
	solve();
	return 0;
}

void solve(){
	int n;
	cin>>n;
	vector<pair<int,int>> ans;
	vector<pair<int,int>> spanning;
	fora(i,0,n){
		int x,y;
		cin>>x>>y;
		if(x>y)
			swap(x,y);
		span.pb({x,y});
	}
	fora(i,0,n){
		int co;
		cin>>co;
		m[i][co]=true;
	}
	sort(span.rbegin(),span.rend());
	int sum=0,count=0;
	fora(i,1,n+1){
		link[i]=i;
		size[i]=1;
	}
	fora(i,0,span.size()){
		if(!same(span[i].ff,span[i].ss)){
			unite(span[i].ff,span[i].ss);
			sum+=spanning[i].ff;
			count++;
			ans.pb({spanning[i].ss.ff,spanning[i].ss.ss});
		}
	}
//		cout<<count<<endl;
		sort(ans.begin(),ans.end());
		if(count==nodes-1){
			cout<<sum<<endl;
			fora(i,0,ans.size()){
				cout<<ans[i].ff<<" "<<ans[i].ss<<endl;
			}
		}else
			cout<<"Impossible"<<endl;
	}
}
