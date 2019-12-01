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
#define int long long

const int MAX = (int)2e6;
int Bmin[MAX], Bmax[MAX];

void add(int B[], int idx){
  for(int i = idx; i < MAX; i += (i & -i)){
    ++B[i];
  }
}

int get(int B[], int idx){
  int total = 0;
  for(int i = idx; i > 0; i -= (i & -i)){
    total += B[i];
  }
  return total;
}

#undef int
int main(){
#define int long long
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  cout.precision(10);
  cout << fixed;
#ifdef LOCAL_DEFINE
  freopen("input.txt","rt", stdin);
#endif
  int Lmin[MAX], Rmin[MAX], Lmax[MAX], Rmax[MAX];
  int a[MAX], deq1[MAX], deq2[MAX], top, bot;
  int n;
  cin >> n;
  for1(i, n){
    cin >> a[i];
  }
  
  // cal Rmin is [i, Rmin[i]] then a[i] is min
  // cal Lmax is [Lmax[i], i] then a[i] is max
  deq1[0] = deq2[0] = 0;
  top = bot = 0;
  
  for1(i, n){
    while(top > 0 && a[deq1[top]] >= a[i]) --top;
    Lmin[i] = deq1[top] + 1;
    deq1[++top] = i;

    while(bot > 0 && a[deq2[bot]] <= a[i]) --bot;
    Lmax[i] = deq2[bot] + 1;
    deq2[++bot] = i;
  }

  // cal Lmin is [Lmin[i], i] then a[i] is min
  // cal Rmax is [i, Rmax[i]] then a[i] is max
  deq1[0] = deq2[0] = n + 1;
  top = bot = 0;
  
  for(int i = n; i > 0; --i){
    while(top > 0 && a[deq1[top]] >= a[i]) --top;
    Rmin[i] = deq1[top] - 1;
    deq1[++top] = i;

    while(bot > 0 && a[deq2[bot]] <= a[i]) --bot;
    Rmax[i] = deq2[bot] - 1;
    deq2[++bot] = i;
  }
  
  // Test
/*  
  cerr << '\n';
  for1(i, n) cerr << Lmin[i] << ' ';
  cerr << '\n';
  for1(i, n) cerr << Rmax[i] << ' ';
  cerr << '\n';
  for1(i, n) cerr << Rmin[i] << ' ';
  cerr << '\n';
  for1(i, n) cerr << Lmax[i] << ' ';
  cerr << '\n';
*/  

  int total = 0;
  // cal (min, max)
  for1(i, n){
    int x = get(Bmin, MAX - 1) - get(Bmin, i - 1);
    int y = get(Bmax, i) - get(Bmax, Lmax[i] - 1);
    total += min(x, y);
    add(Bmin, Rmin[i]);
    add(Bmax, Lmax[i]);
  }
  
  // cal (max, min)
  memset(Bmin, 0, sizeof Bmin);
  memset(Bmax, 0, sizeof Bmax);
  for(int i = n; i > 0; --i){
    int x = get(Bmin, i);
    int y = get(Bmax, Rmax[i]);
    total += min(x, y);
    add(Bmin, Lmin[i]);
    add(Bmax, Rmax[i]);
  }
  cout << total + n << '\n';
#ifdef LOCAL_DEFINE
  cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
  return 0;
}
