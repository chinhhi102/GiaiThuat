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
  int n, l, k;
  cin >> n >> l >> k;
  string s;
  cin >> s;
  sort(all(s));
  vector<string> res(k - 1, string(l, ' '));
  string temp = string(s.begin() + k - 1, s.begin() + k + l - 1);
  s = string(s.begin(), s.begin() + k - 1) + string(s.begin() + k + l - 1, s.end());
  forn(i, (k - 1) * l){
    res[i % (k - 1)][i / (k - 1)] = s[i];
  }
  forn(i, (k - 1) / 2){
    swap(res[i][0], res[k - 2 - i][0]);
  } 
  res.pb(temp);
  s = string(s.begin() + (k - 1) * l, s.end());
  string ss = "";
  forn(i, s.size()){
    ss += s[i];
    if((int)ss.size() == l){
      res.pb(ss);
      ss = "";
    }
  }
  sort(all(res));
  for(auto r : res){
    cout << r << '\n';
  }
#ifdef LOCAL_DEFINE
  cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
  return 0;
}
