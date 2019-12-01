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
const int MAXN = (int)2e5;
#define int long long
int fw[MAXN] = {};
int p[MAXN];
vi child[MAXN];
int res = 0;
int n, k;

void add(int pos, int val){
  while(pos < MAXN){
    fw[pos] += val;
    pos += (pos & -pos);
  }
}

int get(int pos){
  int total = 0;
  while(pos > 0){
    total += fw[pos];
    pos -= (pos & -pos);
  }
  return total;
}

void dfs(int u){
  res += get(u + k) - get(u - k - 1);
  add(u, 1);
  for(int v : child[u]){
    dfs(v);
  }
  add(u, -1);
}
#undef int
int main(){
#define int long long
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  cout.precision(10);
  cout << fixed;
#ifdef LOCAL_DEFINE
  freopen("input.txt","rt", stdin);
#endif
  cin >> n >> k;
  for1(i, n) p[i] = i;
  forn(i, n - 1){
    int a, b;
    cin >> a >> b;
    p[b] = a;
    child[a].pb(b);
  }
  int root = 0;
  for1(i, n){
    if(p[i] == i){
      root = i;
      break;
    }
  }
  dfs(root);
  cout << res << '\n';
#ifdef LOCAL_DEFINE
  cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
  return 0;
}
