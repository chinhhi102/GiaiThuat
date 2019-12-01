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
	map<int,string> m;
	m[0]="zero";
	m[1]="one";
	m[2]="two";
	m[3]="three";
	m[4]="four";
	m[5]="five";
	m[6]="six";
	m[7]="seven";
	m[8]="eight";
	m[9]="nine";
	m[10]="ten";
	m[11]="eleven";
	m[12]="twelve";
	m[13]="thirteen";
	m[14]="fourteen";
	m[15]="fifteen";
	m[16]="sixteen";
	m[17]="seventeen";
	m[18]="eighteen";
	m[19]="nineteen";
	m[20]="twenty";
	m[30]="thirty";
	m[40]="forty";
	m[50]="fifty";
	m[60]="sixty";
	m[70]="seventy";
	m[80]="eighty";
	m[90]="ninety";
	string line;
	while(getline(cin,line)){
		istringstream iss(line);
		string s;
		bool f=1;
		while(iss>>s){
			if(s.size()==1&&s[0]<='9'&&s[0]>='0'){
				s=m[s[0]-'0'];
			}else if(s.size()==2&&s[0]<='9'&&s[0]>='0'&&s[1]<='9'&&s[1]>='0'){
				if(s[1]!='0'&&s[0]!='1'){
					s=m[(s[0]-'0')*10]+'-'+m[s[1]-'0'];
				}else{
					s=m[(s[0]-'0')*10+s[1]-'0'];
				}
			}
			if(f){
				if(s[0]<='z'&&s[0]>='a')
					s[0]-=32;
				f=0;
			}
			cout<<s<<' ';
		}
		cout<<endl;
	}
}
