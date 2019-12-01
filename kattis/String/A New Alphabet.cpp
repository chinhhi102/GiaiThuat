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
	map<char,string> m;
	m['a']=m['A']="@";
	m['b']=m['B']="8";
	m['c']=m['C']="(";
	m['d']=m['D']="|)";
	m['e']=m['E']="3";
	m['f']=m['F']="#";
	m['g']=m['G']="6";
	m['h']=m['H']="[-]";
	m['i']=m['I']="|";
	m['j']=m['J']="_|";
	m['k']=m['K']="|<";
	m['l']=m['L']="1";
	m['m']=m['M']="[]\\/[]";
	m['n']=m['N']="[]\\[]";
	m['o']=m['O']="0";
	m['p']=m['P']="|D";
	m['q']=m['Q']="(,)";
	m['r']=m['R']="|Z";
	m['s']=m['S']="$";
	m['t']=m['T']="']['";
	m['u']=m['U']="|_|";
	m['v']=m['V']="\\/";
	m['w']=m['W']="\\/\\/";
	m['x']=m['X']="}{";
	m['y']=m['Y']="`/";
	m['z']=m['Z']="2";
	string s;
	getline(cin,s);
	fora(i,0,s.size()){
		if(m.count(s[i])!=0)
			cout<<m[s[i]];
		else
			cout<<s[i];
	}
	return 0;
}
