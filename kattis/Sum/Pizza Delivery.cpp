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

ll khoi(vll v,int a,int b){return abs(a-b)*v[b];}

int main(){
    ll n;scll(n);
    fora(i,0,n){
        ll x,y;c2(x,y);
        vector<vll > data;
        data.resize(x,vll(y,0));
        fora(j,0,y) fora(k,0,x) sc(data[k][j]);
                
        vector<ll> dong;
        vector<ll> cot;
        dong.resize(x,0);
        cot.resize(y,0);
        fora(j,0,x) fora(k,0,y){
			dong[k] += data[j][k];
            cot[j]  += data[j][k];
			}

        ll bestX=1e9;
        fora(j,0,dong.size()){
            ll besthere = 0;
            fora(k,0,dong.size())
                besthere += khoi(dong, j, k);
            bestX = min(besthere, bestX);
        }

        ll bestY=1e9;
        fora(j,0,cot.size()){
            ll besthere=0;
            fora(k,0,cot.size())
                besthere += khoi(cot,j,k);
            bestY = min(besthere, bestY);
        }
		
		printf("%lld blocks\n",bestX+bestY);
    }
    return 0;
}
