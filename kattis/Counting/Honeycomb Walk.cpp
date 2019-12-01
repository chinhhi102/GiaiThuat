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

long long honeycomb_walk(int n, long long* walks){
    if (walks[n] < 0){
        walks[n-3] = honeycomb_walk(n-3, walks);
        walks[n-2] = honeycomb_walk(n-2, walks);
        walks[n-1] = honeycomb_walk(n-1, walks);
        walks[n] = (walks[n-1]*n + 24*walks[n-2]*n + 36*walks[n-3]*n - 24*walks[n-2] - 72*walks[n-3])*(n - 1)/ (n * n);
    }
    return walks[n];
}


int main(){
	long long walks[15];
    walks[0] = 1;
    walks[1] = 0;
    walks[2] = 6;
    for (int i = 3; i < 15; i++) walks[i] = -1;
    int n;
    scanf("%d",&n);
    while(n--)
    {
        int path;
        scanf("%d",&path);
        printf("%lld\n",honeycomb_walk(path, walks));
    }
	return 0;
}
