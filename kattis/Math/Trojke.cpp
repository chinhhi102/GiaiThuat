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
struct point {
    int x,y;
};

bool cmp(point& p1, point& p2){
    if(p1.x==p2.x){
        return p1.y<p2.y;
    }
    return p1.x<p2.x;
}
bool line(point& p1,point& p2,point& p3){
    vector<point> v={p1,p2,p3};
    sort(all(v),cmp);
    int xdiff1=v[1].x-v[0].x;
    int ydiff1=v[1].y-v[0].y;
    int xdiff2=v[2].x-v[1].x;
    int ydiff2=v[2].y-v[1].y;
    int gcd1=__gcd(xdiff1,ydiff1);
    xdiff1/=gcd1;
    ydiff1/=gcd1;
    int gcd2=__gcd(xdiff2,ydiff2);
    xdiff2/=gcd2;
    ydiff2/=gcd2;
    return xdiff1==xdiff2&&ydiff1==ydiff2;
}
int main(){
	io;
	solve();
	return 0;
}

void solve(){
	vector<point> v;
    int n;
    cin>>n;
    fora(i,0,n){
        fora(j,0,n){
            char c;
            cin>>c;
            if(c!='.'){
                v.pb({i,j});
            }
        }
    }
    n=v.size();
    int total=0;
    fora(i,0,n){
        fora(j,i+1,n){
            fora(k,j+1,n){
                if(line(v[i],v[j],v[k])){
                    total++;
                }
            }
        }
    }
    cout<<total<<endl;
}
