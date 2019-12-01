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

void solve() {
    ll n, a, b, c, d, x0, y0, m;
    cin >> n >> a >> b >> c >> d >> x0 >> y0 >> m;
    vector<pair<ll,ll> > points;
    ll x = x0;
    ll y = y0;
    points.pb({x,y});
    for(ll i = 1; i < n; i++) {
        x = (a*x+b)%m;
        y = (c*y+d)%m;
        points.pb({x,y});
    }
    ll total = 0;
    for(ll i = 0; i < n; i++) {
        for(ll j = i+1; j < n; j++) {
            for(ll k = j+1; k < n; k++) {
                ll sumx = points[i].first +
                          points[j].first +
                          points[k].first;
                ll sumy = points[i].second +
                          points[j].second +
                          points[k].second;
                if(sumx % 3 == 0 && sumy % 3 == 0) {
                    total++;
                }
            }
        }
    }
    cout << total << endl;
}
int main(){
	io;
	ll cases;
    cin >> cases;
    for(ll i = 1; i <= cases; i++) {
        cout << "Case #" << i << ": ";
        solve();
    }
	return 0;
}
