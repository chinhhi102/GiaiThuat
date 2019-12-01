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
int n;
int next_node=2;
bool valid=true;
int deg[2000];
void bfs(int node){
	if(!valid)return;
	while(deg[node]){
		deg[node]--;
		deg[next_node]--;
		if(next_node>n||node<0){
			valid=false;
			break;
		}
		next_node++;
		bfs(next_node-1);
	}
}
int main(){
	io;
	solve();
	return 0;
}

void solve(){
	cin>>n;
	int total=0;
	fora(i,1,n+1){
		cin>>deg[i];
		total+=deg[i];
		if(deg[i]==0)
			valid=false;
	}
	if(total!=2*(n-1)||!valid){
		cout<<"NO"<<endl;
		return;
	}
	bfs(1);
	fora(i,1,n+1){
		if(deg[i]!=0){
			valid=false;
			break;
		}
	}
	cout<<(valid?"YES":"NO")<<endl;
}
