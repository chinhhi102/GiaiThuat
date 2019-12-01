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
const int MAXN = 1005;

i64 BIT[MAXN][MAXN] = {};

void add(int x, int y, int val){
  for(int i = x; i < MAXN; i += (i & -i)){
    for(int j = y; j < MAXN; j += (j & -j)){
      BIT[i][j] += val;
    }
  }
}

i64 get(int x, int y){
  i64 total = 0;
  for(int i = x; i > 0; i -= (i & -i)){
    for(int j = y; j > 0; j -= (j & -j)){
      total += BIT[i][j];
    }
  }
  return total;
}

i64 get(int x1, int y1, int x2, int y2){
  return get(x2, y2) - get(x2, y1 - 1) - get(x1 - 1, y2) + get(x1 - 1, y1 - 1);
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
  for1(i, n){
    for1(j, n){
      int x;
      cin >> x;
      add(i, j, x);
    }
  }             
  int q;
  cin >> q;
  while(q--){
    int t;
    cin >> t;
    if(t == 1){
      int x, y, val;
      cin >> x >> y >> val;
      add(x, y, val);
    } else {
      int x1, x2, y1, y2;
      cin >> x1 >> y1 >> x2 >> y2;
      cout << get(x1, y1, x2, y2) << '\n';
    }
  }
#ifdef LOCAL_DEFINE
  cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
  return 0;
}
