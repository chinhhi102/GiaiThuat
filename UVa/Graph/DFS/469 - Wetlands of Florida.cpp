#ifndef competitive_programming_H
#define competitive_programming_H
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
#define fix(x) cout<<fixed<<setprecision(x)
#define UNIQUE(c) (c).resize(unique(all(c))-(c).begin())
#define debug freopen("D:\\baiTapLapTrinh\\UVa\\out.txt","w",stdout);
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
#endif
void solve();
int dx[]={1,1,0,-1,-1,-1,0,1};
int dy[]={0,1,1,1,0,-1,-1,-1};

vector<string> grid;

int floodfill(int r,int c,char c1,char c2){
	int R=grid.size();
	int C=grid[0].size();
	if(r<0||r>=R||c<0||c>=C)
		return 0;
	if(grid[r][c]!=c1)
		return 0;
	int ans=1;
	grid[r][c]=c2;
	fora(d,0,8){
		ans+=floodfill(r+dx[d],c+dy[d],c1,c2);
	}
	return ans;
}

int main(){
	io;
	solve();
	return 0;
}

void solve(){
	int TC;
	cin>>TC;
	cin.ignore();
	cin.ignore();
	while(TC--){
		string line;
		vector<pair<int,int>> co;
		vector<string> v;
		while(getline(cin,line)&&line.size()){
			if(line[0]=='L'||line[0]=='W'){
				v.pb(line);
			}else{
				istringstream iss(line);
				int x,y;
				iss>>x>>y;
				co.pb({x,y});
			}
		}
		fora(i,0,co.size()){
			grid=v;
			cout<<floodfill(co[i].ff-1,co[i].ss-1,'W','.')<<endl;
		}
		if(TC)
			cout<<endl;
	}
}
