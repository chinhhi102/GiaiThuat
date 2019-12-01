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
#include <ctype.h>
#include <stack>
#include <iterator>
#include <complex>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <functional>
#include <time.h>
//#include <unordered_map>
using namespace std;

#define io ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
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
#define M_PI 3.14159265358979323846
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
typedef pi coor;
typedef pair<int, coor > platform;
int main(){
	io;
	vector<platform> plat;
	int n;
	cin>>n;
	plat.pb({0,{-1,10001}});
	fora(i,1,n+1){
		int h,x,y;
		cin>>h>>x>>y;
		plat.pb({h,{x,y}});
	}
	sort(plat.begin(),plat.end());
	ll ans=0;
	fora(i,1,n+1){
		bool l=1,r=1;
		fors(j,i,0){
			if(plat[i].ff==plat[j].ff)continue;
			if(plat[i].ss.ff<plat[j].ss.ss&&plat[i].ss.ff>plat[j].ss.ff&&l){
				ans+=(plat[i].ff-plat[j].ff);
				l=0;
			}
			if(plat[i].ss.ss<plat[j].ss.ss&&plat[i].ss.ss>plat[j].ss.ff&&r){
				ans+=(plat[i].ff-plat[j].ff);
				r=0;
			}
			if(plat[i].ss.ss==plat[j].ss.ss&&plat[i].ss.ff<plat[j].ss.ss&&r){
				ans+=(plat[i].ff-plat[j].ff);
				r=0;
			}
			if(plat[i].ss.ff==plat[j].ss.ff&&plat[i].ss.ss>plat[j].ss.ff&&l){
				ans+=(plat[i].ff-plat[j].ff);
				l=0;
			}
			if(l==0&&r==0)break;
		}
	}
	cout<<ans;
	return 0;
}
