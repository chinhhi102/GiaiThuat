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
const int MAXN = (int)4e5;

i64 fw1[MAXN] = {}, fw2[MAXN] = {};
i64 sum[MAXN] = {};

void add(i64 fw[], int pos, int val){
  while(pos < MAXN){
    fw[pos] += val;
    pos += (pos & -pos);
  }
}

void add_range(int l){
  add(fw1, l, 1);
  add(fw2, l, (l - 1));
}

i64 get(i64 fw[], int pos){
  i64 total = 0;
  while(pos > 0){
    total += fw[pos];
    pos -= (pos & -pos);
  }
  return total;
}

i64 prefix_sum(int k){
  return get(fw1, k) * k - get(fw2, k);
}

i64 get_range(int l){
  return prefix_sum(l) - prefix_sum(l - 1);
}

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
  string s;
  cin >> s;
  int a[n + 1] = {};
  i64 total = 0;
  for1(i, n){
    a[i] = a[i - 1] + (s[i - 1] == '(' ? 1 : -1);
  }
  const int N = n + 1;
  for(int i = n; i > 0; --i){
    add_range(a[i] + N + 1);
    add(sum, a[i] + N, a[i]);
    i64 pre = (get(sum, MAXN - 1) - get(sum, a[i - 1] + N));
    i64 sub = (a[i - 1] * (n - i + 1 - get_range(a[i - 1] + 1 + N)));
    total +=  pre - sub;
  }
  cout << total << '\n';
#ifdef LOCAL_DEFINE
  cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
  return 0;
}
