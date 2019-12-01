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
	map<char,string> letter;
	letter['a']=letter['b']=letter['c']="2";
	letter['d']=letter['e']=letter['f']="3";
	letter['g']=letter['h']=letter['i']="4";
	letter['j']=letter['k']=letter['l']="5";
	letter['m']=letter['n']=letter['o']="6";
	letter['p']=letter['q']=letter['r']=letter['s']="7";
	letter['t']=letter['u']=letter['v']="8";
	letter['w']=letter['x']=letter['y']=letter['z']="9";
	map<string,int> dir;
	int n;
	cin>>n;
	fora(i,0,n){
		string s;
		cin>>s;
		string words="";
		fora(j,0,s.size()){
			words+=letter[s[j]];
		}
		dir[words]++;
	}
	string d;
	cin>>d;
	cout<<dir[d];
	return 0;
}
