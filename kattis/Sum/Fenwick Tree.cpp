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

ll n, q;
ll v[5000005];

void update(ll* v, ll index, ll value) {
    index++;
    while(index < n+5) {
        v[index] += value;
        index += index & (-index);
    }
}

ll sum(ll* v, ll index) {
    ll total = v[0];
    while(index > 0) {
        total += v[index];
        index -= index & (-index);
    }
    return total;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    scanf("%lld%lld\n", &n, &q);
    for(int i = 0; i < n+5; i++) {
        v[i] = 0;
    }

    ll index, value;
    for(ll i = 0; i < q; i++) {
        char op;
        scanf("%c", &op);

        if(op == '+') {
            scanf("%lld%lld\n", &index, &value);
            update(v, index, value);
        }
        if(op == '?') {
            scanf("%lld\n", &index);
            printf("%lld\n", sum(v, index));
        }
    }
}