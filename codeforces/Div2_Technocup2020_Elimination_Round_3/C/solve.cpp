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
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    forn(i, n){
      char c;
      cin >> c;
      if(c == '(')
        a[i] = 1;
      else
        a[i] = -1;
    }
    int cur = 0;
    int last = 0;
    vector<pair<int,int>> res;
    forn(i, n){
      if(k == 1) break;
      if(cur == 0){
        int j = i;
        while(j < n && a[j] != 1) j++;
        reverse(a.begin() + i, a.begin() + j + 1);
        if(i != j)
          res.pb({i, j});
        cur += 1;
        continue;
      } else {
        int j = i;
        while(j < n && a[j] != -1) j++;
        reverse(a.begin() + i, a.begin() + j + 1);
        if(i != j)
          res.pb({i, j});
        k--;
        cur -= 1;
        last = i + 1;
      }
    }
    int t = (n - last) / 2;
    for(int i = last; i < n; i++){
      if(t){
        int j = i;
        while(j < n && a[j] != 1) j++;
        reverse(a.begin() + i, a.begin() + j + 1);
        if(i != j)
          res.pb({i, j});
        t--;
      } else {
        break;
      }
    }
    cout << res.size() << '\n';
    forn(i, res.size()){
      cout << res[i].first + 1 << ' ' << res[i].second + 1 << '\n';
    }
  }
#ifdef LOCAL_DEFINE
  cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
  return 0;
}
