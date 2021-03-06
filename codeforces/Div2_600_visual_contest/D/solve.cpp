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

vi ra, p, mi, ma;

int findSet(int x){
  if(x == p[x])
    return x;
  else
    return p[x] = findSet(p[x]);
}

void unionSet(int i, int j){
  int x = findSet(i);
  int y = findSet(j);
  if(x != y){
    if(ra[x] > ra[y]){
      p[y] = x;
      mi[x] = min(mi[x], mi[y]);
      ma[x] = max(ma[x], ma[y]);
    }else{
      p[x] = y;
      mi[y] = min(mi[x], mi[y]);
      ma[y] = max(ma[x], ma[y]);
      if(ra[x] == ra[y]) ++ra[y];
    }
  }
}

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  cout.precision(10);
  cout << fixed;
#ifdef LOCAL_DEFINE
  freopen("input.txt","rt", stdin);
#endif
  int n, m;
  cin >> n >> m;
  ra.assign(n + 1, 0);
  p.resize(n + 1);
  mi.resize(n + 1);
  ma.resize(n + 1);
  for1(i, n){
    p[i] = mi[i] = ma[i] = i;
  }
  int x, y;
  forn(i, m){
    cin >> x >> y;
    unionSet(x, y);
  }
  map<int,int> g;
  for1(i, n){
    int cur = findSet(i);
    if(mi[cur] == ma[cur]){
      g[cur] = 0;
    }else{
      g[mi[cur]] = 1;
      g[ma[cur]] = -1;
    }
  }
  int total = 0, cur = 0;
  for(auto i:g){
    cur += (i.second >= 0 ? 1 : -1);
    if(i.second >= 0) total += (cur > 1);
    cur -= (i.second == 0);
  }
  cout << total << '\n';
#ifdef LOCAL_DEFINE
  cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
  return 0;
}
