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

void solve();
bool findreciprocal(ll target,ll curr){
    // if (n*m)/(n+m) == x
    // then n = (x*m)/(m-x)
    ll top=target*curr;
    ll bot=curr-target;
    if(bot<=0){
        return false;
    }
    if(top%bot==0){
        return true;
    }
    return false;
}
int main(){
	io;
	solve();
	return 0;
}

void solve(){
	string s;
    while(cin>>s){
        reverse(s.begin(),s.end());
        s.pop_back();
        s.pop_back();
        reverse(s.begin(),s.end()); 
        ll n=stoi(s);
        ll count=0;
        for(ll i=n;i<=n*2;i++){
            if(findreciprocal(n,i)){
                count++;
            }
        }
        cout<<count<<endl;
    }

}
