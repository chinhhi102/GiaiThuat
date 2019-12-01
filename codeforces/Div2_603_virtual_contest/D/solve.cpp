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

vi p[30];
bool vis[30] = {};

void dfs(int u){
  vi ti;
  vis[u] = true;
  forn(i, 26){
    for(int val : p[u]){
      if(p[i].size() && !vis[i]){
        if(binary_search(all(p[i]), val)){
          ti.pb(i);
        }
      }
    }
  }
  for(int v : ti){
    if(!vis[v] && p[v].size()){
      dfs(v);
    }
  }
}

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  cout.precision(10);
  cout << fixed;
#ifdef LOCAL_DEFINE
  freopen("input.txt","rt", stdin);
#endif
  int n;
  cin >> n;
  forn(i, n){
    string s;
    cin >> s;
    for(char c : s){
      p[c - 'a'].pb(i);
    }
  }
  int total = 0;
  forn(i, 26){
    if(p[i].size() && !vis[i]){
      ++total;
      dfs(i);
    }
  }
  cout << total << '\n';
#ifdef LOCAL_DEFINE
  cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
  return 0;
}
