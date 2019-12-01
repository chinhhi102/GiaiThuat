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
int length=0,max_length=0;
void BFS(vector<unordered_set<int>>& streets,queue<int>& path,queue<int>& npath){
	length++;
	while(!path.empty()){
		int curr=path.front();
		path.pop();
		if(streets[curr].count(0)!=0)
			max_length=max(max_length,length+1);
		for(auto child:streets[curr]){
			
			if(child==0)continue;cout<<child<<" ";
			npath.push(child);
			if(curr==0)continue;
			streets[child].erase(curr);
		}
//		cout<<endl;
	}
}
int main(){
	io;
	solve();
	return 0;
}

void solve(){
	 int n;
	 while(cin>>n&&n!=0){
	 	length=0,max_length=0;
	 	int m;
	 	cin>>m;
		vector<unordered_set<int>> streets(n);
		fora(i,0,m){
			int x,y;
			cin>>x>>y;
			streets[x].insert(y);
			streets[y].insert(x);
		}
		queue<int> path;
		path.push(0);
		while(!path.empty()){
			queue<int> npath;
			BFS(streets,path,npath);
			path=npath;
//			cout<<path.size()<<endl;
cout<<endl;
		}
		cout<<max_length<<endl;
	 }
}