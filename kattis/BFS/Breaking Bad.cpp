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
#include <unordered_map>
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
int find(vector<int>& disjoint, int n) {
    if(disjoint[n] == -1) {
        return n;
    }

    disjoint[n] = find(disjoint, disjoint[n]);
    return disjoint[n];
}
void join(vector<int>& disjoint, int a, int b) {
    a = find(disjoint, a);
    b = find(disjoint, b);

    if(a == b) {
        return;
    }

    disjoint[a] = b;
}
bool bfs(vector<vector<int> >& adj, vector<int>& visited, int start) {
    queue<pair<int, int> > q;
    q.push({start, 0});

    while(!q.empty()) {
        pair<int, int> p = q.front();
        q.pop();
        visited[p.first] = p.second;
        for(vector<int>::iterator i=adj[p.first].begin();i!=adj[p.first].end();i++) {
            if(visited[*i] == p.second) {
                return false;
            }
            if(visited[*i] == -1) {
                q.push({*i, (p.second + 1)%2});
            }
        }
    }
    return true;
}
int main(){
	io;
	int n;
    cin >> n;
    vector<string> inttostr;
    unordered_map<string, int> strtoint;
    for(int i = 0; i < n; i++) {
        string s;
        cin >> s;
        inttostr.push_back(s);
        strtoint[s] = i;
    }

    // Build necessary data structures
    vector<int> disjoint;
    disjoint.resize(n, -1);
    vector<vector<int>> adj;
    adj.resize(n);

    // Add items to disjoint set and adjacency list
    int c;
    cin >> c;
    for(int i = 0; i < c; i++) {
        string a, b;
        cin >> a >> b;
        int a1, b1;
        a1 = strtoint[a];
        b1 = strtoint[b];

        join(disjoint, a1, b1);
        adj[a1].push_back(b1);
        adj[b1].push_back(a1);
    }

    // Break into clusters of items
    unordered_map<int, vector<int>> items;
    for(int i = 0; i < disjoint.size(); i++) {
        items[find(disjoint, i)].push_back(i);
    }

    // For each cluster of items, run a BFS to see if it is OK
    vector<int> visited;
    visited.resize(n, -1);
    bool works = true;
    for(auto cluster : items) {
        works &= bfs(adj, visited, cluster.second[0]);
    }

    // Print the result
    if(!works) {
        cout << "impossible" << endl;
    }
    else {
        for(int i = 0; i < visited.size(); i++) {
            if(visited[i] == 0) {
                cout << inttostr[i] << " ";
            }
        }
        cout <<endl;
        for(int i = 0; i < visited.size(); i++) {
            if(visited[i] == 1) {
                cout << inttostr[i] << " ";
            }
        }
        cout <<endl;
    }
	return 0;
}
