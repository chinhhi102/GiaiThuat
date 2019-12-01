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
		ll hi=INF,low=0;
		string q,t;
		vector<int> div;
		ll value;
		fora(i,0,n){
			cin>>q>>t>>value;
			if(q.compare("less")==0){
				hi=min(hi,value);
			}else if(q.compare("greater")==0){
				low=max(low,value);
			}else{
				div.pb(value);
			}
//			cout<<low<<" "<<hi<<" "<<div.size()<<endl;
		}
		if(hi==INF){
			cout<<"infinite"<<endl;
		}else{
			sort(div.begin(),div.end());
			int maxx;
			if(div.size()==0)
				maxx=1;
			else
				maxx=div[div.size()-1];
			bool p=true;
//			cout<<hi<<" ";
			for(int i=maxx;i<hi;i+=maxx){
				if(i<=low)continue;
				bool dk=true;
				if(div.size()==0){
					p=false;
					cout<<i<<" ";
					continue;
				}
				fora(j,0,div.size()-1){
					if(i%div[j]){
						dk=false;
						break;
					}
				}
				if(dk){
					cout<<i<<" ";
					p=false;
				}
			}
			if(p)
				cout<<"none"<<endl;
		}
	}
}
