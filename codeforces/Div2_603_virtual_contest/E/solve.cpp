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

#define mid (s + e) / 2

struct segnode{
  int s, e, lazy, maxv, minv;
  segnode *l, *r;
  segnode(int _s, int _e){
    s = _s;
    e = _e;
    lazy = maxv = minv = 0;
    if(s != e) {
      l = new segnode(s, mid);
      r = new segnode(mid + 1, e);
    }
  }
  void pre(){
    maxv += lazy;
    minv += lazy;
    if(s != e){
      l -> lazy += lazy;
      r -> lazy += lazy;
    }
    lazy = 0;
  }
  void update(int a, int b, int val){
    if(s == a && e == b){
      lazy += val;
      return;
    }
    else if(a > mid) r -> update(a, b, val);
    else if(b <= mid) l -> update(a, b, val);
    else {
      l -> update(a, mid, val);
      r -> update(mid + 1, b, val);
    }
    l -> pre();
    r -> pre();
    minv = min(l -> minv, r -> minv);
    maxv = max(l -> maxv, r -> maxv);
  }
  int maxq(int a, int b){
    pre();
    if(s == a && e == b) return maxv;
    if(a > mid) return r -> maxq(a, b);
    if(b <= mid) return l -> maxq(a, b);
    return max(l -> maxq(a, mid), r -> maxq(mid + 1, b));
  }
  int minq(int a, int b){
    pre();
    if(s == a && e == b) return minv;
    if(a > mid) return r -> minq(a, b);
    if(b <= mid) return l -> minq(a, b);
    return min(l -> minq(a, mid), r -> minq(mid + 1, b));
  }
} *root;  

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  cout.precision(10);
  cout << fixed;
#ifdef LOCAL_DEFINE
  freopen("input.txt","rt", stdin);
#endif
  int n, pos = 0;
  cin >> n;
  root = new segnode(0, n - 1);
  string reals(n, ' ');
  string s;
  cin >> s;
  for(char c : s){
    if(c == 'L') pos = max(pos - 1, 0);
    else if(c == 'R') ++pos;
    else{
      if(reals[pos] == '(') root -> update(pos, n - 1, -1);
      else if(reals[pos] == ')') root -> update(pos, n - 1, 1);
      if(c == '(') root -> update(pos, n - 1, 1);
      else if(c == ')') root -> update(pos, n - 1, -1);
      reals[pos] = c;
    }
    if(root -> minq(0, n - 1) < 0 || root -> minq(n - 1, n - 1) != 0) cout << -1 << ' ';
    else cout << root -> maxq(0, n - 1) << ' ';
  }
#ifdef LOCAL_DEFINE
  cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
  return 0;
}
