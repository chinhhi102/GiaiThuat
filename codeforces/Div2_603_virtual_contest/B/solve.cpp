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
  while(T--){
    int n;
    cin >> n;
    vector<string> a(n);
    map<string, int> d;
    int total = 0;
    vector<string> res;
    forn(i, n){
      cin >> a[i];
      if(d.count(a[i])) ++total;
      d[a[i]]++;
    }
    auto fin = [](map<string, int> &d, string s){
      forn(i, 4){
        string te = s;
        forn(j, 10){
          s[i] = char(j + '0');
          if(d.count(s) == 0){
           ++d[s];
           return s;
          }
        }
        s = te;
      }
      ++d[s];
      return s;
    };
    for(string& s : a){
      if(d[s] > 1){
        --d[s];
        s = fin(d, s);
      }
      res.pb(s);
    }
    cout << total << '\n';
    forn(i, res.size()){
      cout << res[i] << '\n';
    }
  }
#ifdef LOCAL_DEFINE
  cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
  return 0;
}
