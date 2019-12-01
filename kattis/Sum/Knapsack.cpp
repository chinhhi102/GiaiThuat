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

struct object {
    int v; // value
    int w; // weight
};

int main(){
	io;
	double C;
    int n,c;
    int sol[2001][2001];
    bool mark[2001][2001];
    object a[2001];
//    while (cin>>C>>n){
    while (scanf("%lf %d",&C,&n)==2){
        c = C;
        memset(mark,false,sizeof(mark));
        for (int i=0;i<n;i++)
            scanf("%d %d",&a[i+1].v,&a[i+1].w);
        for (int j=0;j<=c;j++)
            sol[0][j] = 0;
        for (int i=1;i<=n;i++)
            for (int j=0;j<=c;j++){
                if (a[i].w <= j && sol[i-1][j] < sol[i-1][j-a[i].w] + a[i].v){
                    sol[i][j] = sol[i-1][j-a[i].w] + a[i].v;
                    mark[i][j] = true;
                }
                else
                    sol[i][j] = sol[i-1][j];
            }
        // try with set
        set <int> final_sol;
        int ii=n , jj=c;
        while(ii && jj){
            if (mark[ii][jj]){
                final_sol.insert(ii-1);
                jj -= a[ii].w;
            }
            ii--;
        }

        // try with printf
        printf("%d\n",final_sol.size());
        for (set<int>::iterator it=final_sol.begin(); it!=final_sol.end(); ++it)
            printf("%s%d",(it!=final_sol.begin()?" ":""),*it);
        printf("\n");
    }
	return 0;
}
