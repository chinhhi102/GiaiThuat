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
int id,n;
int a[1000][1000];
vector<vector<int>> res;
vector<int> path;
vector<int> visited;
void DFS(int curr){
	path.push_back(curr);
	if(curr==id){
		res.push_back(path);
		return;
	}
	visited[curr]=1;
	for(int i=0;i<=n;i++){
//		cout<<curr<<' '<<i<<endl;
		if(visited[i]||!a[curr][i])continue;
		DFS(i);
		path.pop_back();
	}
}

int main(){
	io;
	solve();
	return 0;
}

void solve(){
	cin>>n>>id;
	visited.resize(n+2);
	for(int i=0;i<=n;i++){
		for(int j=0;j<=n;j++){
			cin>>a[i][j];
		}
	}
//	cout<<a[5][3]<<endl;
	for(int i=0;i<=n;i++){
		for(int j=0;j<=n;j++){
			if(a[i][j])
				DFS(0);
		}
	}
//	sort(all(res));
	for(int i=0;i<res.size();i++){
		for(int j=0;j<res[i].size();j++){
			if(j==res[i].size()-1)
				cout<<res[i][j];
			else
				cout<<res[i][j]<<" -> ";
		}
		cout<<endl;
	}
}
/*
5 4
0 1 0 1 0 0
1 0 1 0 1 1
0 1 0 0 1 0
1 0 0 0 1 0
0 1 1 1 0 1
0 1 0 0 1 0
*/
