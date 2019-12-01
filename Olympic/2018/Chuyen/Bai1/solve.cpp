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

bool cmp(pair<pair<int, int>, int> p1, pair<pair<int, int>, int> p2){
  if(max(p1.first.first, p1.first.second) == max(p2.first.first, p2.first.second)){
    return p1.second < p2.second;
  }
  return max(p1.first.first, p1.first.second) < max(p2.first.first, p2.first.second);
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
  pair<pair<int, int>, int> a[n + 1];
  forn(i, n){
    int x, y;
    cin >> x >> y;
    a[i].first.first = abs(x);
    a[i].first.second = abs(y);
    a[i].second = i;
  }
  sort(a, a + n, cmp);
  bool is = true;
  vector<int> res;
  forn(i, n){
    if(!is) break;
    if(i >= max(a[i].first.first, a[i].first.second)) is = false;
    res.pb(a[i].second);
  }
  if(is){
    forn(i, res.size()) cout << res[i] + 1 << ' ';
  } else {
    cout << -1;
  }
#ifdef LOCAL_DEFINE
  cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
  return 0;
}
