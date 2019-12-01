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
int dx[]={1,0,-1,0};
int dy[]={0,1,0,-1};
int main(){
	io;
	solve();
	return 0;
}

void solve(){
	int n,m;
	cin>>n>>m;
	vector<vector<char>> v;
	v.resize(n+2,vector<char> (m+2,'0'));
	fora(i,1,n+1)
		fora(j,1,m+1)
			cin>>v[i][j];
	queue<pair<int,int>> q;
	q.push({0,0});
	while(!q.empty()){
		int i=q.front().ff;
		int j=q.front().ss;
		q.pop();
		if(v[i][j]!='0')continue;
		v[i][j]='2';
		fora(k,0,4){
			int ni=i+dx[k];
			int nj=j+dy[k];
			if(ni<0||nj<0||ni>n+1||nj>m+1)continue;
			if(v[ni][nj]=='0')
				q.push({ni,nj});
		}
	}
	int total=0;
	fora(i,0,n+2)
		fora(j,0,m+2){
			if(v[i][j]=='1'){
				fora(k,0,4){
					if(v[i+dx[k]][j+dy[k]]=='2')
						total++;
				}
			}
		}
	cout<<total<<endl;
}
