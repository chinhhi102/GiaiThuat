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
  vi t1, t2;
  map<int, int> m1, m2;
  forn(i, n){
    int x;
    cin >> x;
    t1.pb(x);
    m1[x]++;
  }
  forn(i, n){
    int x;
    cin >> x;
    t2.pb(x);
    m2[x]++;
  }
  sort(all(t1));
  sort(all(t2));
  pair<int, int> minx = {-1, (int)1e9};
  for(auto i : m1){
    if(minx.se > i.se){
      minx.fi = i.fi;
      minx.se = i.se;
    }
  }
  for(auto i : m2){
    if(minx.se == i.se){
      int x = (i.fi - minx.fi) + (m * (i.fi < minx.fi));
      vi temp = t1;
      for(auto &j : temp){
        j += x;
        j %= m;
      }               
      sort(all(temp));
      if(temp == t2){
        cout << x << '\n';
        break;
      }
    }
  }
#ifdef LOCAL_DEFINE
  cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
  return 0;
}
