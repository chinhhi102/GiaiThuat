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

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  cout.precision(10);
  cout << fixed;
#ifdef LOCAL_DEFINE
  freopen("input.txt","rt", stdin);
#endif
  int n, m;
  cin >> n >> m;
  map<string, vector<string>> g;
  map<string, set<string>> dk;
  vector<string> ip;
  forn(i, n){
    string s;
    cin >> s;
    ip.pb(s);
  }
  forn(i, m){
    string u, v;
    cin >> v >> u;
    g[u].pb(v);
    dk[v].insert(u);
  }
  bool r = true;
  vector<string> res;
  map<string, bool> use;
  map<string, string> p;
  for(string cur : ip){
    if(dk[cur].size() == 0){
      if(!use[cur]){
        res.pb(cur);
        use[cur] = true;
      }
      for(string u : ip){
        p[u] = u;
      }
      queue<string> q;
      q.push(cur);
      while(!q.empty()){
        string u = q.front();
        q.pop();
        if(!r) break;
        for(string v : g[u]){
          if(p[v] == p[u]){
            r = false;
            break;
          }
          p[v] = p[u];
          dk[v].erase(u);
          if(dk[v].size() == 0){
            if(!use[v]){
              res.pb(v);
              use[v] = true;
            }
            q.push(v);
          }
        }
      }
    }
  }
  if(r && (int)res.size() == n) for(string u : res) cout << u << ' ';
  else cout << "You should take care of it later" << '\n';
#ifdef LOCAL_DEFINE
  cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
  return 0;
}
