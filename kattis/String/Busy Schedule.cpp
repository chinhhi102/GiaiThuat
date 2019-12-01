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

int main(){
	io;
	solve();
	return 0;
}

void solve(){
	int n;
	while(cin>>n&&n!=0){
		vector<pair<int,int>> time[2];
		char ap,c;
		int h,m;
		fora(i,0,n){
			cin>>h>>c>>m>>ap>>c>>c>>c;
			if(ap=='a')
				time[0].pb({h%12,m});
			else
				time[1].pb({h%12,m});
		}
		sort(all(time[0]));
		sort(all(time[1]));
		fora(j,0,2)
			fora(i,0,time[j].size()){
				cout<<(time[j][i].ff==0?12:time[j][i].ff)<<":";
				if(time[j][i].ss<10)
					cout<<0<<time[j][i].ss;
				else
					cout<<time[j][i].ss;
				cout<<" "<<(j==0?"a":"p")<<".m."<<endl;
			}
		cout<<endl;
	}
}
