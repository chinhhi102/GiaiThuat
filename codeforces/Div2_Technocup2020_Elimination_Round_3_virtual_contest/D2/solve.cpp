#include<bits/stdc++.h>

using namespace std;

//#define mp make_pair
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

const int MAX = 2*(int)1e5 + 123;
int f[4 * MAX] = {};
int a[MAX];
map<pii, int> res;
vpi queries; 
vi k_pos[MAX];
map<int, vi> mp;

void update(int p, int l, int r, int pos){
  if(l == r){
    ++f[p];
    return;
  }
  int mid = (l + r) / 2;
  int p1 = (p << 1) + 1;
  int p2 = (p << 1) + 2;
  if(pos <= mid){
    update(p1, l, mid, pos);
  } else {
    update(p2, mid + 1, r, pos);
  }
  f[p] = f[p1] + f[p2];
};
int get(int p, int l, int r, int sum){
  if(l == r){
    return l;
  }
  int mid = (l + r) / 2;
  int p1 = (p << 1) + 1;
  int p2 = (p << 1) + 2;
  if(sum <= f[p1]){
    return get(p1, l, mid, sum);
  } else {
    return get(p2, mid + 1, r, sum - f[p1]);
  }
};
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  cout.precision(10);
  cout << fixed;
#ifdef LOCAL_DEFINE
  freopen("input.txt","rt", stdin);
#endif 
  int n, m;
  cin >> n;
  forn(i, n){
    cin >> a[i];
    mp[a[i]].pb(i);
  }
  cin >> m;
  forn(i, m){
    int k, pos;
    cin >> k >> pos;
    k_pos[k].pb(pos);
    queries.pb({k, pos});
  }
  forn(i, MAX){
    sort(all(k_pos[i]));
  }
  int cur = 0;
  for(auto it = mp.rbegin(); it != mp.rend(); ++it){
    vi arpos = it -> second;
    for(auto i : arpos){
      update(0, 0, n - 1, i);
      ++cur;
      for(auto pos : k_pos[cur]){
        int r = get(0, 0, n - 1, pos);
        res[{cur, pos}] = a[r];
      }
    }
  }
  for(auto q : queries){
    cout << res[q] << '\n';
  }
#ifdef LOCAL_DEFINE
  cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
  return 0;
}
