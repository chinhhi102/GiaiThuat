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
  map<int, vector<int>> m;
  vector<int> a[n];
  for1(i, n - 2){
    int x, y, z;
    cin >> x >> y >> z;
    a[i].pb(x);
    a[i].pb(y);
    a[i].pb(z);
    m[x].pb(i);
    m[y].pb(i);
    m[z].pb(i);
  }
  int st;
  for(auto i:m){
    if(i.second.size() == 1){
      st = i.first;
      break;
    }
  }
  bool use[(int)1e6] = {};
  bool ause[(int)1e6] = {};
  queue<vector<int>> q;
  vector<int> cur;
  q.push(a[m[st][0]]);
  ause[m[st][0]] = 1;
  forn(i, n){
    if(!use[st])
      cout << st << ' ';
    use[st] = 1;
    int nst;
    int er = m[st][0];
    cur = a[er];
    forn(j, cur.size()){
      forn(k, m[cur[j]].size()){
        if(m[cur[j]][k] == er){
          m[cur[j]].erase(m[cur[j]].begin() + k);
          if(i < 2 && m[cur[j]].size() == 1){
            if(cur[j] == q.front()[0] || cur[j] == q.front()[1] || cur[j] == q.front()[2]){
              nst = cur[j];
              q.push(a[m[cur[j]][0]]);
              ause[m[cur[j]][0]] = 1;
            }
          }
        }
      }
    }
    if(i >= 2){
      vector<int> tt = q.front();
      q.pop();
      forn(j, tt.size())
        if(!use[tt[j]]){
          nst = tt[j];
          forn(k, m[nst].size())
            if(!ause[m[nst][k]]){
              q.push(a[m[nst][k]]);
            }
        }
    }
    st = nst;
  }
  cout << st << '\n';
#ifdef LOCAL_DEFINE
  cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
  return 0;
}
