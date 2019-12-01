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

int main(){
	io;
	int n,m;
    while(cin>>n>>m){
        if(n==0&&m==0){
            break;
        }
        vector<vector<pair<ld,int> > > adj(n);
        for(int i = 0; i < m; i++) {
            int n1, n2;
            ld w;
            cin>>n1>>n2>>w;
            adj[n1].push_back({w, n2});
            adj[n2].push_back({w, n1});
        }

        vector<bool> vis(n, false);
        vector<ld> dist(n, 0);

        priority_queue<pair<ld,int> > pq;
        pq.push({1,0});

        while(!pq.empty()) {
            int curr = pq.top().second;
            ld size = pq.top().first;
//            printf("%.4Lf %ld\n",pq.top().first,pq.top().second);
            pq.pop();

            if(vis[curr]) {
                continue;
            }
//            printf("%.4Lf %ld\n",pq.top().first,pq.top().second);
            vis[curr] = true;
            dist[curr] = size;

            for(int i=0;i<adj[curr].size();i++){
                int next = adj[curr][i].ss;
                ld fact = adj[curr][i].ff;
                pq.push({size * fact, next});
            }
        }
//        cout<<fixed;
//        cout.precision(4);
//        cout<<dist[n-1]<<endl;
        printf("%.4Lf\n",dist[n-1]);
    }
	return 0;
}
