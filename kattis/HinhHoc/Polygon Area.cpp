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
#define fora(i,a,b) for(int i=a;i<=b;i++)
#define fors(i,a,b) for(int i=a;i>=b;i--)
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

typedef struct vertex vt;

struct vertex{
	int x,y;
};

int det(vt v1,vt v2){
    return v1.x*v2.y - v1.y*v2.x;
}

int main(){
	while(1){
        int n;
        sc(n);
        if (!n) break;
        vt vertices[n];
        fora(i,0,n-1)scanf("%d %d",&vertices[i].x,&vertices[i].y);
        int sum = 0;
        fora(i,0,n-2) sum+=det(vertices[i],vertices[i+1]);
        sum+=det(vertices[n-1],vertices[0]);
        if (sum < 0) printf("CW %.1f\n", -sum / 2.0);
        else printf("CCW %.1f\n", sum / 2.0);
    }
	return 0;
}
