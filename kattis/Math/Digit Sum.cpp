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

long long digit_sum (long long x) {
  	int res=0;
  	while (x > 0) { 
  		res += x%10; 
		x /= 10; 
	}
  	return res;
}

long long total_sum (long long x){
  int d = x%10;
  return x==0?0:d*(d-1)/2+d*digit_sum(x/10)+10*total_sum(x/10)+(x/10)*45;
}

int main(){
	int t;  
    cin >> t;
    while (t--) {
    long long a,b;
    cin>>a>>b;
    cout<<total_sum(b+1)-total_sum(a)<<endl;
  }
	return 0;
}
