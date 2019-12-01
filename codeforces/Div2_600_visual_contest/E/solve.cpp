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

struct node{
  int x, r;
  bool operator < (node &other){
    return x < other.x;
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
  cin >> n >> m;
  int dp[2 * m + 1];
  memset(dp, 0x3f, sizeof dp);
  dp[0] = 0;
  node arr[n];
  forn(i, n){
    cin >> arr[i].x >> arr[i].r;
  }
  sort(arr, arr + n);
  int pre = 0;
  forn(i, n){
    for(int j = 0; arr[i].x + arr[i].r + j <= 2 * m; ++j){
      pre = arr[i].x - arr[i].r - j - 1;
      pre = max(0, pre);
      int id = arr[i].x + arr[i].r + j;
      dp[id] = min(dp[id], dp[pre] + j);
    }
    ford(j, 2*m){
      dp[j] = min(dp[j], dp[j + 1]);
    }
  }
  cout << dp[m] << '\n';
#ifdef LOCAL_DEFINE
  cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
  return 0;
}
