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
#define INF 1000000000000000000
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
const int MAXN = 10004;
const int MAXW = 102;
const int MOD = 1000000007;
int n,w,h;
int dp[MAXW][MAXN];
void solve();
inline int prod(const int& a,const int& b) {
    return (1LL*a*b)%MOD;
}
inline int sum(const int& a,const int& b){
    int c=a+b;
    if(c>=MOD){
        c-=MOD;
    }
    return c;
}
int sol(int cols,int ribbon){
    if(ribbon<0||ribbon>cols*h)
        return 0;
    if(cols==1||ribbon==0)
        return 1;
    int& ret=dp[cols][ribbon];
    if(ret!=-1)
        return ret;
    ret=0;
    fora(height,0,h+1){
        ret=sum(ret,sol(cols-1,ribbon-height));
    }
    return ret;
}
int main(){
	io;
	solve();
	return 0;
}

void solve(){
	cin>>n>>w>>h;
	memset(dp,-1,sizeof(dp));
    int ans=0;
    fora(ribbon,0,n+1){
        ans=sum(ans,sol(w,ribbon));
    }
    fora(height,0,h+1){
        if(1LL*height*w<= n)
            ans=sum(ans,MOD-1);
    }
    cout<<ans;
}
