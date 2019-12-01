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
typedef pair<ll,ll> pt;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<bool> vb;
typedef vector<vector<int> > vvi;
typedef map<int,int> mi;
typedef map<long,long> mll;
long long mag(pt p) {
    return 1LL * p.first * p.first + 1LL * p.second * p.second;
}
pt add(pt a, pt b) {
    return pt { a.first + b.first, a.second + b.second };
}
pt sub(pt a, pt b) {
    return pt { a.first - b.first, a.second - b.second };
}

pt pts[3];

int main(){
	io;
	long long x, y;
    for (int i = 0; i < 3; ++i) {
        scanf("%lld %lld", &x, &y);
        pts[i] = {x, y};
    }

    for (int i = 0; i < 3; ++i) {
        pt a = sub(pts[(i + 1) % 3], pts[i]);
        pt b = sub(pts[(i + 2) % 3], pts[i]);

        if (mag(a) == mag(b)) {
            pt ans = add(pts[i], a);
            ans = add(ans, b);

            printf("%lld %lld\n", ans.first, ans.second);
            return 0;
        }
    }
	return 0;
}
