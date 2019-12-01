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
#include <assert.h>
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
typedef unsigned long long ULL;
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
ULL cnt(unsigned m){
	ULL mc=1;
	unsigned mleft=m,mright=0,pow10=1; 
  	for(int i=0;mleft;i++){
	    assert(mleft*pow10+mright==m);
	    int digi=mleft%10;
	    mleft/=10;
	    mc+=digi?mleft*pow10:(mleft-1)*pow10+mright+1;
	    mright=digi*pow10+mright;
	    pow10*=10;
  	}
  	return mc;
}
int zcnt(unsigned m){
  	int mc=0;
  	do{
  		if(!(m%10))mc++;
    	m/=10;
  	}while(m);
  	return mc;
}
int main(){
	io;
	solve();
	return 0;
}
void solve(){
	long long m,n;
  	while(1){
	    scanf("%lld%lld",&m,&n);
	    if(m<0)break;
	    assert(m<=n);
	    ULL mc,nc;
	    mc=cnt(m);
	    nc=cnt(n);
	    printf("%llu\n",nc-mc+zcnt(m));
  	}
}
