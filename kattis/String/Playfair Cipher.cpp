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
//#include <tuple>
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
	io;
	string enc,mes;
	getline(cin,enc);
	getline(cin,mes);
	map<char,pair<int,int> > m;
	map<pair<int,int>, char> rev;
	int x=0,y=0;
	fora(i,0,enc.size()){
		if(enc[i]==' ')continue;
		if(m.count(enc[i])==0){
			m[enc[i]]={x,y};
			rev[{x,y}]=enc[i];
			y++;
			if(y==5){
				x++;
				y=0;
			}
		}
	}
	for(char i='a';i<='z';i++){
		if(i=='q')continue;
		if(m.count(i)==0){
			m[i]={x,y};
			rev[{x,y}]=i;
			y++;
			if(y==5){
				x++;
				y=0;
			}
		}
	}
	string actual;
	string nos;
	fora(i,0,mes.size()){
		if(mes[i]==' ')continue;
		nos.pb(mes[i]);
	}
	int ind=0;
	fora(i,0,nos.size()){
		if(ind%2&&actual[ind-1]==nos[i]){
			actual.pb('x');
			ind++;
		}
		actual.pb(nos[i]);
		ind++;
	}
	string ans="";
	int n=actual.size();
	for(int i=0;i<n;i+=2){
		char c1=actual[i];
		char c2;
		if(i==n-1){
			c2='x';
		}else{
			c2=actual[i+1];
		}
		if(c1==c2){
			c2='x';
		}
		int x1=m[c1].ff;
		int y1=m[c1].ss;
		int x2=m[c2].ff;
		int y2=m[c2].ss;
		if(m[c1].ff==m[c2].ff){
			ans+=rev[{x1,(y1+1)%5}];
			ans+=rev[{x2,(y2+1)%5}];
		}else if(m[c1].ss==m[c2].ss){
			ans+=rev[{(x1+1)%5,y1}];
			ans+=rev[{(x2+1)%5,y2}];			
		}else{
			ans+=rev[{x1,y2}];
			ans+=rev[{x2,y1}];
		}
	}
	fora(i,0,ans.size()){
		cout<<(char)(ans[i]-32);
	}
	return 0;
}
