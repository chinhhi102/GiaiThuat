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
#define sq(a) ((a)*(a))
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

double x[101];
double y[101];
bool sour[101];
	
int main(){
	io;
	while (1) {
        double d;
        int n;
        scanf("%lf %d", &d, &n);
        if (n == 0) break;
        d *= d;
        int i, j;
        for (i = 0; i < n; ++i) {
            sour[i] = 0;
            scanf("%lf %lf", &x[i], &y[i]);
            for (j = 0; j < i; ++j) {
                double dist = sq(x[i] - x[j]) + sq(y[i] - y[j]);
                if (dist <= d) {
                    sour[i] = 1;
                    sour[j] = 1;
                }
            }
        }
        int ans = 0;
        for (i = 0; i < n; ++i) {
            if (sour[i] > 0) {
                ++ans;
            }
        }
        printf("%d sour, %d sweet\n", ans, n-ans);
    }
	return 0;
}
