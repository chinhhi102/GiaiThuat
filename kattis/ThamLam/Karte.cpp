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
#define M_PI 3.14159265358979323846
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
	string s;
	cin>>s;
	int a[4]={13,13,13,13};
	map<string,int> m;
	fora(i,0,s.size()){
		string t="";
		t+=s[i];
		t+=s[i+1];
		t+=s[i+2];
//		cout<<t<<" ";
		if(t[0]=='P')
			a[0]--;
		else if(t[0]=='K')
			a[1]--;
		else if(t[0]=='H')
			a[2]--;
		else if(t[0]=='T')
			a[3]--;
		if(m[t]){
			cout<<"GRESKA";
			return 0;
		}else{
			m[t]++;
		}
		i+=2;
	}
	fora(i,0,4)
		cout<<a[i]<<" ";
	return 0;
}
