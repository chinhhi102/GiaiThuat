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
  int n;
  cin >> n;
  if(n == 1){
    cout << "ANSWER " << 1 << endl;
    return 0;
  }
  int m = 1;
  int tt = n - 1;
  while(tt >> 1){
    ++m;
    tt >>= 1;
  }
  tt = n - 1;
  int gb = m - 1;
  int rank[(1 << m) + 1];
  set<int> data[4 * ((1 << m) + 1)];
  
  for1(i, (1 << m)){
    rank[i] = 1;      
    data[1].insert(i);
  }
  map<int, int> res;

  while(tt){
    int i = 1;
    vi ask;
    vi nt1, nt2;
    int mod = (1 << (gb + 1));
    while(i <= n){
      for(int j = 0; j < (1 << gb); ++j){
        int val = (i / mod) * mod + j + 1;
        rank[val] *= 2;
        nt1.pb(val);
        if(val <= n){
          ask.pb(val);
        }
        ++i;
      }
      for(int j = 0; j < (1 << gb); ++j){
        int val = ((i - 1) / mod) * mod + mod / 2 + j + 1;
        rank[val] = rank[val] * 2 + 1;
        nt2.pb(val);
        ++i;
      }                                                          
    }                                  
    cout << "ASK " << ask.size() << " ";
    forn(i, ask.size()) cout << ask[i] << ' ';
    cout << endl;
    
    vector<bool> use((1 << m) + 1, 0);
    forn(i, ask.size()){
      int x;
      cin >> x;
      use[x] = true;
    }

    for(int u : nt1){
      for(int v = 1; v <= (1 << m); ++v){
        if(use[v] && data[rank[u] / 2].count(v)){
          data[rank[u]].insert(v);
        }
      }
    }
                     
    for(int u : nt2){
      for(int v = 1; v <= (1 << m); ++v){
        if(!use[v] && data[rank[u] / 2].count(v)){
          data[rank[u]].insert(v);
        }
      }
    }
                 
    for(int u = 1; u <= n; ++u){
      if(data[rank[u]].size() == 1){
        res[u] = *data[rank[u]].begin();
      }
    }

    --gb;
    tt >>= 1;
  }
  cout << "ANSWER ";
  for(auto i : res) cout << i.second << ' ';
  cout << endl;
#ifdef LOCAL_DEFINE
  cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
  return 0;
}
