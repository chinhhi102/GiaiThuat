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
int dx[]={1,0};
int dy[]={0,1};
string s[19];
map<string,bool> m;
string temp="";
int d=0,n;
void sol(int y,int x){
	temp+=s[y][x];
	if(y==n-1&&x==n-1){
		for(int i=0;i<=(temp.size()/2);i++){
			if(temp[i]!=temp[temp.size()-i-1]){
				return;
			}
		}
		m[temp]=true;
//		fora(i,0,temp.size())
//			cout<<temp[i];
//		cout<<endl;
	}else{
		fora(i,0,2){
			int ny=y+dy[i];
			int nx=x+dx[i];
			if(nx>=n||ny>=n)continue;
			sol(ny,nx);
			temp.pop_back();
		}
	}
}
int main(){
	io;
	solve();
	return 0;
}

void solve(){
	cin>>n;
	fora(i,0,n)
		cin>>s[i];
	sol(0,0);
	cout<<m.size()<<endl;
}
