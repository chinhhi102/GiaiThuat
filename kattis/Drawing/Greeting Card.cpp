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

ll dx[] = {0, 1118, 1680, 2018};
ll dy[] = {2018, 1680, 1118, 0};

int main(){
	io;
	int n;
    scanf("%d",&n);
    ll x, y;
    ll ans = 0LL;
    set<pair<ll,ll> > pts;

    fora(i,0,n){
        scanf("%lld %lld", &x,&y);
        set<pair<ll, ll> > found;
        for (int b1 = -1; b1 <= 1; b1 += 2) {
            for (int b2 = -1; b2 <= 1; b2 += 2) {
                for (int d = 0; d < 4; d++) {
                    ll nx = x + b1 * dx[d];
                    ll ny = y + b2 * dy[d];
                    if (pts.find({nx, ny}) != pts.end()){
                        found.insert({nx, ny});
                    }
 //                  printf("%d ",found.size());
                }
//                printf("\n");
            }
        }
        ans += found.size();
        pts.insert({x, y});
//        printf("\n%lld \n",ans);
    }

    printf("%lld\n", ans);

	return 0;
}