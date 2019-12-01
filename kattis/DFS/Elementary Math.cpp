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
bool match(ll curr, vector<vector<ll> >& adj, vector<ll>& l, vector<ll>& r, vector<ll>& vis) {
    if(vis[curr]) return false;
    vis[curr] = true;

    fora(next,0,adj[curr].size()) {
        if(r[adj[curr][next]] == -1 || match(r[adj[curr][next]], adj, l, r, vis)) {
            l[curr] = adj[curr][next];
            r[adj[curr][next]] = curr;
            return true;
        }
    }
    return false;
}
vector<ll> bipartite(vector<vector<ll> >& adj, ll n, ll m) {
    vector<ll> l, r, vis;
    l.resize(n, -1);
    r.resize(m, -1);
    vis.resize(n);

    bool works = true;
    while(works) {
        works = false;
        fill(vis.begin(), vis.end(), 0);
        for(ll i = 0; i < n; i++) {
            if(l[i] == -1) {
                works |= match(i, adj, l, r, vis);
            }
        }
    }

    return l;
}
void makework(ll l, ll r, ll end) {
    cout << l << " ";

    if(l+r == end) {
        cout << "+";
    }
    else if(l - r == end) {
        cout << "-";
    }
    else {
        cout << "*";
    }

    cout << " " << r << " = " << end << endl;
}
int main(){
	io;
	ll n;
    cin >> n;
    vector<pair<ll,ll> > input;
    vector<vector<ll> > adj(n);

    map<ll,ll> numtonode;
    vector<ll>  nodetonum;
    ll rcount = 0;

    for(ll i = 0; i < n; i++) {
        pair<ll,ll> p;
        cin >> p.first >> p.second;
        input.pb(p);

        ll num1 = p.first + p.second;
        if(numtonode.count(num1) == 0) {
            numtonode[num1] = rcount;
            nodetonum.pb(num1);
            rcount++;
        }

        ll num2 = p.first - p.second;
        if(numtonode.count(num2) == 0) {
            numtonode[num2] = rcount;
            nodetonum.pb(num2);
            rcount++;
        }

        ll num3 = p.first * p.second;
        if(numtonode.count(num3) == 0) {
            numtonode[num3] = rcount;
            nodetonum.pb(num3);
            rcount++;
        }

        adj[i].pb(numtonode[num1]);
        adj[i].pb(numtonode[num2]);
        adj[i].pb(numtonode[num3]);
    }

    vector<ll> matching = bipartite(adj, n, rcount);

    ll total = 0;
    for(ll i = 0; i < n; i++) {
        total += (matching[i] != -1);
    }

    if(total == n) {
        for(ll i = 0; i < n; i++) {
            makework(input[i].first, input[i].second, nodetonum[matching[i]]);
        }
    }
    else {
        cout << "impossible" << endl;
    }
	return 0;
}
