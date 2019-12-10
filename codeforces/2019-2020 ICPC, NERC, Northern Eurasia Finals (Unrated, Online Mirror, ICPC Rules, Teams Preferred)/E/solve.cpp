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
  int a[m + 1][n + 1];
  for1(i, m){
    for1(j, n){
      cin >> a[i][j];
    }
  }
/*  for1(i, m){
    for1(j, n){
      cerr << a[i][j] << ' ';
    }
    cerr << '\n';
  } */
  pair<int, int> f[n + 1];
  int kc;
  vi res(m + 1, 0);
  for1(i, n - 1){
    vi cur;
    kc = 0;
    for1(j, m){
      f[j] = {a[j][i] - a[j][n], j};
      kc += a[j][n] - a[j][i];
    }
    sort(f + 1, f + m + 1);
    for1(j, m){
      if(kc > 0){
        kc += f[j].fi;
        cur.pb(f[j].se);
      } else break;
    }
    if(cur.size() < res.size()) res = cur;
  }
  cout << res.size() << '\n';
  forn(i, res.size()){
    cout << res[i] << ' ';
  }
#ifdef LOCAL_DEFINE
  cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
  return 0;
}
