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
//#include <tuple>
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
//typedef vector<tuple<int,int,int> > date;
int stoi(string x){
	int sum=0;
	fora(i,0,x.size()){
		sum=sum*10+(x[i]-'0');
	}
	return sum;
}
int main(){
	io;
	string name,d1,d2;
	int c;
	int n;
	cin>>n;
	fora(i,0,n){
		cin>>name>>d1>>d2>>c;
		int i1=stoi(d1.substr(0,4));
		int i2=stoi(d2.substr(0,4));
		cout<<name;
		if(i1>2009||i2>1990){
			cout<<" eligible\n";
		}else if(c>40)
			cout<<" ineligible\n";
		else
			cout<<" coach petitions\n";
	}
	return 0;
}
