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
  int T;
  cin >> T;
  int tc = 1;
  while(T--){
    int n, k;
    cin >> n >> k;
    int a[n + 1];
    int L[n + 1] = {};
    int R[n + 1] = {};
    int D[n + 2];
    for1(i, n){
      cin >> a[i];
    }
    int res = 0;
    int top = 0;
    D[0] = 0;
    for1(i, n){
      while(top > 0 && a[D[top]] >= a[i] && a[D[top]] - a[i] <= k) --top;
      L[i] = D[top] + 1;
      D[++top] = i;
    }
    top = 0;
    D[0] = n + 1;
    for (int i = n; i >= 1; --i) {
      while (top > 0 && a[D[top]] >= a[i] && a[D[top]] - a[i] <= k) --top;
      R[i] = D[top] - 1;
      D[++top] = i;
    }
    for1(i, n){
      res = max(res, R[i] - L[i] + 1);
    }
    top = 0;
    D[0] = 0;
    for1(i, n){
      while(top > 0 && a[D[top]] <= a[i] && a[i] - a[D[top]] <= k) --top;
      L[i] = D[top] + 1;
      D[++top] = i;
    }
    top = 0;
    D[0] = n + 1;
    for (int i = n; i >= 1; --i) {
      while (top > 0 && a[D[top]] <= a[i] && a[i] - a[D[top]] <= k) --top;
      R[i] = D[top] - 1;
      D[++top] = i;
    }
    for1(i, n){
      res = max(res, R[i] - L[i] + 1);
    }
    cout << "Case #" << tc++ << ": " << res << " day" << (res == 1 ? "\n" : "s\n");
  }
#ifdef LOCAL_DEFINE
  cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
  return 0;
}