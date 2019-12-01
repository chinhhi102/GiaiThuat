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

int main(){
	io;
	solve();
	return 0;
}

void solve(){
	map<char,map<char,int>> m;
	map<char,int> mm;
	mm['.']=1;mm[',']=2;mm['?']=3;mm['!']=4;mm['1']=5;
	m['.']=m[',']=m['?']=m['!']=m['1']=mm;
	mm.clear();
	mm['a']=1;mm['b']=2;mm['c']=3;mm['2']=4;
	m['a']=m['b']=m['c']=m['2']=mm;
	mm.clear();
	mm['d']=1;mm['e']=2;mm['f']=3;mm['3']=4;
	m['d']=m['e']=m['f']=m['3']=mm;
	mm.clear();
	mm['g']=1;mm['h']=2;mm['i']=3;mm['4']=4;
	m['g']=m['h']=m['i']=m['4']=mm;
	mm.clear();
	mm['j']=1;mm['k']=2;mm['l']=3;mm['5']=4;
	m['j']=m['k']=m['l']=m['5']=mm;
	mm.clear();
	mm['m']=1;mm['n']=2;mm['o']=3;mm['6']=4;
	m['m']=m['n']=m['o']=m['6']=mm;
	mm.clear();
	mm['p']=1;mm['q']=2;mm['r']=3;mm['s']=4;mm['7']=5;
	m['p']=m['q']=m['r']=m['s']=m['7']=mm;
	mm.clear();
	mm['t']=1;mm['u']=2;mm['v']=3;mm['8']=4;
	m['t']=m['u']=m['v']=m['8']=mm;
	mm.clear();
	mm['w']=1;mm['x']=2;mm['y']=3;mm['z']=4;mm['9']=5;
	m['w']=m['x']=m['y']=m['z']=m['9']=mm;
	mm.clear();
	mm['_']=1;mm['0']=2;
	m['_']=m['0']=mm;
	
	int n;
	cin>>n;
	while(n--){
		string s;
		cin>>s;
		mm.clear();
		mm['.']=1;mm[',']=2;mm['?']=3;mm['!']=4;mm['1']=5;
		map<char,int> cur=mm;
		int total=0;
		fora(i,0,s.size()){
			if(m[s[i]]!=cur){
				total++;
				cur.clear();
				cur=m[s[i]];
			}
			total+=m[s[i]][s[i]];
		}
		cout<<total<<endl;
	}
}
