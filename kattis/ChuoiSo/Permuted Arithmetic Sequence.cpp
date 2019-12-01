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
#define fora(i,a,b) for(int i=a;i<=b;i++)
#define fors(i,a,b) for(int i=a;i>=b;i--)
#define men(a) menset(a,0,sizeof(a))
#define sc(x) scanf("%d",&x);
#define scll(x) scanf("%lld",&x);
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
	char res[3][50]={"arithmetic","permuted arithmetic","non-arithmetic"};
	int n;
	sc(n);
	while(n--){
		int ns,tmp,f=1;
		sc(ns);
		int a[ns];
		fora(i,0,ns-1)sc(a[i]);
		tmp=a[1]-a[0];
		for(int i=1;i<ns&&f;i++)f=!(a[i]-a[i-1]-tmp);
		if(f)printf("%s\n",res[0]);
			else{
			f=1;
			sort(a,a+ns);
			tmp=a[1]-a[0];
			for(int i=1;i<ns&&f;i++)f=!(a[i]-a[i-1]-tmp);
			printf("%s\n",f?res[1]:res[2]);
		}
	}
	return 0;
}
