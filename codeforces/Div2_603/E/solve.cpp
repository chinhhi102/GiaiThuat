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

#define m (s + e) / 2
struct segnode{
  int s, e, minv, maxv, lazy;
  segnode *l, *r;
  segnode(int _s, int _e){
    s = _s;
    e = _e;
    minv = maxv = lazy = 0;
    if(s != e) {
      l = new segnode(s, m);
      r = new segnode(m + 1, e);
    }
  }
  void propagate(){
    minv += lazy;
    maxv += lazy;
    if(s != e){
      l -> lazy += lazy;
      r -> lazy += lazy;
    }
    lazy = 0;
  }
  void update(int a, int b, int d){
    if(s == a && e == b){
      lazy += d;
      return;
    }
    else if(a > m) r -> update(a, b, d);
    else if(b <= m) l -> update(a, b, d);
    else {
      l -> update(a, m, d);
      r -> update(m + 1, b, d);
    }
    l -> propagate();
    r -> propagate();
    minv = min(l -> minv, r -> minv);
    maxv = max(l -> maxv, r -> maxv);
  }
  int minq(int a, int b){
    propagate();
    if(s == a && e == b) return minv;
    if(a > m) return r -> minq(a, b);
    if(b <= m) return l -> minq(a, b);
    return min(l -> minq(a, m), r -> minq(m + 1, b));
  }
  int maxq(int a, int b){
    propagate();
    if(s == a && e == b) return maxv;
    if(a > m) return r -> maxq(a, b);
    if(b <= m) return l -> maxq(a, b);
    return max(l -> maxq(a, m), r -> maxq(m + 1, b));
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
   int n, ptr = 0;
   cin >> n;
   string s;
   cin >> s;
   char reals[n];
   root = new segnode(0, n - 1);
   forn(i, n) reals[i] = ' ';
   for(auto c : s){
     if(c == 'L') ptr = max(0, ptr - 1);
     else if(c == 'R') ++ptr;
     else {
       if(reals[ptr] == '(') root -> update(ptr, n - 1, -1);
       else if(reals[ptr] == ')') root -> update(ptr, n - 1, 1);
       if(c == '(') root -> update(ptr, n - 1, 1);
       else if(c == ')') root -> update(ptr, n - 1, -1);
       reals[ptr] = c;
     }
     if(root -> minq(0, n - 1) < 0 || root -> minq(n - 1, n - 1) != 0) cout << -1 << ' ';
     else cout << root -> maxq(0, n - 1) << ' '; 
   }
#ifdef LOCAL_DEFINE
  cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
  return 0;
}
