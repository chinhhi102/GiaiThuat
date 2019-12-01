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
#include <list>
#include <stack>
#include <iterator>
#include <complex>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
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

int main(){
	map<string,vector<string> > station;
	int n;
	sc(n);
	cin.ignore();
	while(n--){
		string s;
		string beg="",end="",temp="";
		getline(cin,s);
		int i=0;
		for(;i<s.size();i++){
			if(s[i]=' ')break;
			else
			beg+=s[i];
		}
		for(;i<s.size();i++){
			if(s[i]=' '){
				station[temp].pb(beg);
				end=temp;
				temp="";
			}else temp+=s[i];
		}
		station[beg].pb(end);
		fora(i,0,station[beg].size())
			station[beg][i].pb(end);
		string bg="",ed="";
		cin>>bg>>ed;
		string x=bg;
		bool f=1;
		while(station[x]){
			if(station[x]){
				x=station[x];
			}else{
				f=0;
				break;
			}
		}
		if(f)
			while(station[bg]!=ed){
				cout<<bg<<" ";
				bg=station[bg];
			}
		else
			cout<<"no route found";
	}
	return 0;
}
