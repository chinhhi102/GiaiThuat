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
	int n,x;
	cin>>n>>x;
	int weight[n];
	fora(i,0,n)
		cin>>weight[i];
	vector<pair<int,int>> best(1<<n,pair<int,int>(n,0));
	vector<vector<int>> kt(1<<n);
	best[0]={0,0};
	fora(s,1,(1<<n)){
		best[s]={n,0};
		fora(p,0,n){
			if(s&(1<<p)){
				kt[(s^(1<<p))].pb(p);
//				cout<<best[s].ff<<" "<<best[s].ss<<endl;
				pair<int,int>& option=best[s^(1<<p)];
				if(option.ss+weight[p]<=x){
					option.ss+=weight[p];
				}else{
					option.ff++;
					option.ss=weight[p];
				}
//				if((s^(1<<p))!=-1){
//					cout<<(s^(1<<p))<<"=";
//					cout<<option.ff<<" "<<option.ss<<" "<<p<<endl;
//				}
				best[s]=min(best[s],option);
//				cout<<best[s].ff<<" "<<best[s].ss<<endl;
			}
		}
//		cout<<endl;
	}
	fora(s,0,(1<<n)){
		fora(i,0,kt[s].size())
			cout<<kt[s][i]<<" ";
		cout<<endl;
	}
//	cout<<best[(1<<n)-1].ff+1;
}
/*
5 10
2 3 3 5 6
*/
