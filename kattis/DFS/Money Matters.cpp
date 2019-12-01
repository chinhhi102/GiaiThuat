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

vector< vector<int> > f(10000,vector<int>(10000));
long long debt[10000];
bool visited[10000];
long long sum;

void dfs(int node) {
    if (visited[node])
        return;
    visited[node] = true;
    sum += debt[node];
    for (int i = 0; i < f[node].size(); ++i) {
        if (!visited[f[node][i]])
            dfs(f[node][i]);
    }
}

int main(){
	int N, M, a, b;
    bool works = true;
    scanf("%d%d",&N,&M);
    for (int i = 0; i < N; ++i) { // debts/owed
        scanf("%lld", &debt[i]);
        visited[i] = false;
    }
    for (int i = 0; i < M; ++i) { // friendships
        scanf("%d%d",&a,&b);
        f[a].push_back(b);
        f[b].push_back(a);
    }

    for (int i = 0; i < N; ++i) {
        sum = 0;
        dfs(i);
        if(sum != 0){
            // cout << "Impossible at i = " << i << ", sum = " << sum << endl;
            works = false;
            break;
        }
    }

    if(works)
        cout << "POSSIBLE";
    else 
        cout << "IMPOSSIBLE";
    cout << endl;
	return 0;
}
