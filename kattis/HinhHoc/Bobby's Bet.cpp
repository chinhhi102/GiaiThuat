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
int _binomial[11][11];
int binomial(int n, int k){
    return k<0||k>n?0:_binomial[n][k];
}
int main(){
	io;
	_binomial[0][0] = 1;
    fora(n,1,11){
        fora(k,0,n+1){
            _binomial[n][k] = binomial(n-1,k-1)+binomial(n-1,k);
        }
    }
    int n;
    cin>>n;
    while(n--){
    	int r,s,x,y,w;
	    cin>>r>>s>>x>>y>>w;
 	    double above_or_eq=(s-r+1.0)/s, below=(1-above_or_eq), p_win=0, p_lose=0;
	    fora(i,x,y+1)
			p_win += binomial(y,i)*pow(above_or_eq,i)*pow(below, y-i);
    	p_lose = 1 - p_win;
    	cout<<(p_win*(w-1)+p_lose*(-1)>0?"yes\n":"no\n");
	}
    return 0;
}
