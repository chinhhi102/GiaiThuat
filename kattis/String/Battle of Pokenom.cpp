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
#define debug freopen("D:\\baiTapLapTrinh\\UVa\\temp.txt","w",stdout);
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

int main(){
	io;
	solve();
	return 0;
}

void solve(){
	debug;
	int T;
	cin>>T;
	while(T--){
		int k;
		cin>>k;
		int pa=0,pb=0,S=0,C=0;
		bool f=0;
		char a,b;
		string tmp="";
		fora(i,0,k){
			int t=k-i;
			cin>>a>>b;
			if(a=='E'&&!f)
				pa++;
			if((pa>pb+t||pb>pa+t-1)&&!f)
				S=i*2+1,f=1;
			if(b=='E'&&!f)
				pb++;
			if((pa>pb+t-1||pb>pa+t-1)&&!f)
				S=i*2+2,f=1;
			tmp+=a;
			tmp+=b;
		}
		if(!f)
			S=k*2;
		int bb=S/2;
		int aa=(S%2)?S/2+1:S/2;
		int faila=0,failb=0;
		bool fa=0,fb=0;
		if(aa==pa)
			fa=1;
		if(pa==0)
			fa=1;
		if(bb==pb)
			fb=1;
		if(pb==0)
			fb=1;
			fora(i,0,tmp.size()){
				if(fa&&fb)break;
				C++;
				if(i%2){
					if(!fb&&tmp[i]=='E')
						pb--;
//					cout<<(pb)<<' '<<bb-(i/2)-1<<endl;
					if(!pb||(pb==bb-(i/2)-1))
						fb=1;
				}else{
					if(!fa&&tmp[i]=='E')
						pa--;
					if(!pa||(pa==aa-(i/2)-1))
						fa=1;
				}
			}
		cout<<S<<' '<<C<<endl;
	}
}
