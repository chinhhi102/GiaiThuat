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
  int n;
  cin >> n;
  set<int> s;
  map<int,int> ck;
  vi res;
  int last = 0;
  forn(i, n){
    int x;
    cin >> x;
    if(x < 0){
      x = -x;
      if(s.count(x) == 0){
        cout << -1;
        return 0;
      }
      s.erase(x);
      if(s.size() == 0){
        res.pb(i - last);
        last = i + 1;
        ck.clear();
      }
    }else{
      if(s.count(x) == 1 || ck[x]){
        cout << -1;
        return 0;
      }
      ck[x] = true;
      s.insert(x);
    }
  }
  if(s.size() != 0)return cout << -1, 0;
  cout << res.size() << '\n';
  forn(i, res.size()) cout << res[i] + 1 << ' ';
#ifdef LOCAL_DEFINE
  cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
  return 0;
}