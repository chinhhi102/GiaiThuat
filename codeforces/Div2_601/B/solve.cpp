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
  while(T--){
    int n, m;
    cin >> n >> m;
    int a[n + 1];
    int idx = 0, idy = 0;
    a[0] = (int)1e9;
    for1(i, n){
      cin >> a[i];
      if(a[i] < a[idx]){
        idy = idx;
        idx = i;
      } else if(a[i] < a[idy]){
        idy = i;
      }
    }
    if(m < n){
      cout << -1 << '\n';
    } else {
      int k = m - n;
      int res = 0;
      vector<pair<int, int>> result;
      for1(i, n){
        if(k > 0 && i != idx && i != idy && (i % n + 1) != idx && (i % n + 1) != idy && a[i] + a[i % n + 1] + a[idx] + a[idy] > 2 * a[idx] + a[i] + a[i % n + 1]){
          k--;
          res += 2 * 
          result.push_back({i, idx});
          result.push_back({(i % n) + 1, idx});
        } else {
          res += a[i] + a[(i % n) + 1];
          result.push_back({i, (i % n) + 1});
        }
      }
      result.resize(m, {idx, idy});
      res += k * (a[idx] + a[idy]);     
      cout << res << '\n';
      forn(i, result.size()){
        cout << result[i].first << ' ' << result[i].second << '\n';
      }
    }
  }
#ifdef LOCAL_DEFINE
  cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
  return 0;
}
