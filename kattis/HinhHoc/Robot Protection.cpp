#ifndef competitive_programming_H
#define competitive_programming_H
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
#define fix(x) cout<<fixed<<setprecision(x)
#define UNIQUE(c) (c).resize(unique(all(c))-(c).begin())
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
#endif
void solve();
ll ccw(const pi& a,const pi& b,const pi& c){
    ll x1=b.ff-a.ff;
    ll y1=b.ss-a.ss;
    ll x2=c.ff-a.ff;
    ll y2=c.ss-a.ss;
    return x1*y2-x2*y1;
}
int main(){
	io;
	solve();
	return 0;
}

void solve(){
	int n;
    while(cin>>n&&n!=0){
    	ll x,y;
        vector<pi> pts;
        fora(i,0,n){
        	cin>>x>>y;
        	pts.pb({x,y});
        }
        sort(all(pts));
        UNIQUE(pts);
        vector<pi> hull;
        if(pts.size()<=2){
            hull=pts;
        }else{
            fora(qqq,0,2){
                int start=hull.size();
                fora(i,0,n){
                    while(hull.size()>=start+2&&ccw(hull[hull.size()-2],hull[hull.size()-1],pts[i])<=0){
                        hull.pop_back();
                    }
                    hull.push_back(pts[i]);
                }
                hull.pop_back();
                reverse(all(pts));
            }
        }
        int sz=hull.size();
        if(hull.size()<=2){
        	fix(2)<<0<<endl;
        }else{
            ll area=hull[sz-1].ff*hull[0].ss-hull[sz-1].ss*hull[0].ff;
            fora(i,0,sz-1){
                area+=hull[i].ff*hull[i+1].ss-hull[i].ss*hull[i+1].ff;
            }
            cout<<area/2<<'.'<<(area%2?5:0)<<endl;
        }
    }
}
