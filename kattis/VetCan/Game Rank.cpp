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
	map<int,int> dk;
	fora(i,1,26){
		if(i<11)
			dk[i]=5;
		else if(i<16)
			dk[i]=4;
		else if(i<21)
			dk[i]=3;
		else dk[i]=2;
	}
	string s;
	cin>>s;
	int lv=25;
	int star=0;
	int p=0;
	bool bonus=false,leg=false;
	fora(i,0,s.size()){
		if(s[i]=='W'){
			star++;
			p++;
			if(p>2) bonus=true;
			if(bonus&&lv>5)
				star++;
			if(dk[lv]<star){
				lv--;
				star-=dk[lv+1];
				if(lv==0)
				 leg=true;
			}
		}else{
			if(lv==20&&star==0)continue;
			bonus=false;
			p=0;
			if(lv<21)star--;
			if(star<0){
				lv++;
				star=dk[lv]-1;
			}
		}
	}
	if(leg)
		cout<<"Legend";
	else
		cout<<lv;
}
