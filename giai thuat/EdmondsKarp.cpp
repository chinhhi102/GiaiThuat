#include<bits/stdc++.h>

using namespace std;

#define mp make_pair
#define mt make_tuple
#define fi first
#define se second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define forn(i, n) for(int i = 0; i < (int)n; ++i)
#define for1(i, n) for(int i = 1; i <= (int)n; ++i)
#define ford(i, n) for(int i = (int)n - 1; i >= 0; --i)
#define fore(i, a, b) for(int i = (int)a, i < (int)b; ++i)

typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vpi;
typedef vector<vi> vvi;
typedef long long i64;
typedef vector<i64> vi64;
typedef vector<vi64> vvi64;
typedef vector<i64, i64> pi64;
typedef double ld;

const int INF = 0x3f3f3f3f;
const i64 inf = 0x3f3f3f3f3f3f3f3f;
const double eps = 1e-1;
const double PI = acos(-1.0);

int res[MAX_V][MAX_V], mf, f, s, t;
vi p;

void augment(int v, int minEdge){
  if(v == s){
    f = minEdge;
    return;
  } else if(p[v] != -1) {
    augment(p[v], min(minEdge, res[p[v]][v]));
    res[v][p[v]] += f;
  }
}

// main
  mf  = 0;
  while(1){
    f = 0;
    // run BFS
    vi dist(MAX_V, INF);
    dist[0] = 0;
    queue<int> q;
    q.pb(s);
    p.assign(MAX_V, -1);
    while(!q.empty()){
      int u = q.front();
      q.pop();
      if(u == t) break;
      for(int v = 0; v < MAX_V; ++v){
        if(res[u][v] > 0 && dist[v] = INF){
          dist[v] = dist[u] + 1;
          q.pb(v);
          p[v] = u;
        }
      }
    }
    augment(t, INF);
    if(f == 0) break;
    mf += f;
  }

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  cout.precision(10);
  cout << fixed;
#ifdef LOCAL_DEFINE
  freopen("input.txt","rt", stdin);
#endif
  
#ifdef LOCAL_DEFINE
  cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
  return 0;
}
