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
int toString(int x);
int main(){
	io;
	solve();
	return 0;
}

void solve(){
	map<vector<string>,int> m;
	map<int,vector<string>> mm;
	vector<string> a(7);
	a[0]="xxxxx";
	a[1]="x   x";
	a[2]="x   x";
	a[3]="x   x";
	a[4]="x   x";
	a[5]="x   x";
	a[6]="xxxxx";
	m[a]=0;
	mm[0]=a;
	a[0]="    x";
	a[1]="    x";
	a[2]="    x";
	a[3]="    x";
	a[4]="    x";
	a[5]="    x";
	a[6]="    x";
	m[a]=1;
	mm[1]=a;
	a[0]="xxxxx";
	a[1]="    x";
	a[2]="    x";
	a[3]="xxxxx";
	a[4]="x    ";
	a[5]="x    ";
	a[6]="xxxxx";
	m[a]=2;
	mm[2]=a;
	a[0]="xxxxx";
	a[1]="    x";
	a[2]="    x";
	a[3]="xxxxx";
	a[4]="    x";
	a[5]="    x";
	a[6]="xxxxx";
	m[a]=3;
	mm[3]=a;
	a[0]="x   x";
	a[1]="x   x";
	a[2]="x   x";
	a[3]="xxxxx";
	a[4]="    x";
	a[5]="    x";
	a[6]="    x";
	m[a]=4;
	mm[4]=a;
	a[0]="xxxxx";
	a[1]="x    ";
	a[2]="x    ";
	a[3]="xxxxx";
	a[4]="    x";
	a[5]="    x";
	a[6]="xxxxx";
	m[a]=5;
	mm[5]=a;
	a[0]="xxxxx";
	a[1]="x    ";
	a[2]="x    ";
	a[3]="xxxxx";
	a[4]="x   x";
	a[5]="x   x";
	a[6]="xxxxx";
	m[a]=6;
	mm[6]=a;
	a[0]="xxxxx";
	a[1]="    x";
	a[2]="    x";
	a[3]="    x";
	a[4]="    x";
	a[5]="    x";
	a[6]="    x";
	m[a]=7;
	mm[7]=a;
	a[0]="xxxxx";
	a[1]="x   x";
	a[2]="x   x";
	a[3]="xxxxx";
	a[4]="x   x";
	a[5]="x   x";
	a[6]="xxxxx";
	m[a]=8;
	mm[8]=a;
	a[0]="xxxxx";
	a[1]="x   x";
	a[2]="x   x";
	a[3]="xxxxx";
	a[4]="    x";
	a[5]="    x";
	a[6]="xxxxx";
	m[a]=9;
	mm[9]=a;
	a[0]="     ";
	a[1]="  x  ";
	a[2]="  x  ";
	a[3]="xxxxx";
	a[4]="  x  ";
	a[5]="  x  ";
	a[6]="     ";
	m[a]=-1;
	mm[-1]=a;
	string line[7];
	vector<vector<string>> v;
	int tong=0;
	fora(i,0,7){
		getline(cin,line[i]);
		if(i){
			line[i].resize(tong*5+tong-1,' ');
		}
//		cout<<line[i]<<endl;
		int j=0,id=0,sz=line[i].size();
		while(j<sz){
			if(!i){
				vector<string> vv;
				v.pb(vv);
			}
			v[id++].pb(string(line[i].begin()+j,line[i].begin()+j+5));
//			cout<<string(line[i].begin()+j,line[i].begin()+j+5)<<endl;
			j+=6;
		}
		tong=max(tong,id);
	}
//	fora(i,0,7){
//		fora(j,0,v.size()){
//			cout<<v[j][i]<<' ';
//		}
//		cout<<endl;
//	}
	ll aa=0,bb=0;
	bool f=true;
	fora(i,0,v.size()){
		if(m[v[i]]<0){
			f=false;
			continue;
		}
		if(f){
			aa=aa*10+m[v[i]];
		}else{		
			bb=bb*10+m[v[i]];
		}
	}
	aa+=bb;
	vector<int> res;
	while(aa){
		res.push_back(aa%10);
		aa/=10;
	}
//	res.assign(res.rbegin(),res.rend());
	fora(i,0,7){
		fors(j,res.size(),0){
			cout<<mm[res[j]][i]<<" ";
		}
		if(i-6)
			cout<<endl;
	}
}
