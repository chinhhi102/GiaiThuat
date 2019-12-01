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

vector<int> Primes;
bitset<10000000> bs;
const int MAX = (int)1e9;
const int MAXN = (int)5e5;
int f[MAXN * 4] = {};
int B1[MAXN * 4] = {}, B2[MAXN * 4] = {};
int N = MAXN * 4;
void add(int b[], int idx, int x){
  while(idx < N){
    b[idx] += x;
    idx += (idx & -idx);
  }
}

void range_add(int l, int r, int x){
  add(B1, l, x);
  add(B1, r + 1, -x);
  add(B2, l, x * (l - 1));
  add(B2, r + 1, -x * r);
}

int sum(int b[], int idx){
  int total = 0;
  while(idx > 0){
    total += b[idx];
    idx -= (idx & -idx);
  }
  return total;
}

int prefix_sum(int idx){
  return sum(B1, idx) * idx - sum(B2, idx);
}

int range_sum(int l, int r){
  return prefix_sum(r) - prefix_sum(l - 1);
}

void sieve(){
  bs.set();
  bs[0] = 0;
  Primes.pb(2);
  for(int i = 4; i <= sqrt(MAX); i += 2) bs[i] = 0;
  for(int i = 3; i <= sqrt(MAX); i += 2){
    if(bs[i]){
      for(int j = i * i; j <= sqrt(MAX); j += i){
        bs[j] = 0;
      }
      Primes.pb(i);
    }
  }
}

bool check_Prime(int n){
  if(n == 1) return false;
  for(int i = 0; i < (int)Primes.size() && Primes[i] * Primes[i] <= n; ++i){
    if(n % Primes[i] == 0){
      return false;
    }
  }
  return true;
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
  sieve();
  int n;
  cin >> n;
  int a[MAXN];
  a[0] = 0;
  int total = 0;
  for1(i, n){
    int x;
    cin >> x;
    x = check_Prime(x) ? 1 : -1;
    a[i] = a[i - 1] + x;
  }
  const int Bound = n + 1;
  for(int i = n; i > 0; --i){
    range_add(a[i] + 1 + Bound, 4 * MAXN - 1, 1);
    total += (n - i + 1 - range_sum(a[i - 1] + Bound, a[i - 1] + Bound));
  }
  cout << total << '\n';
#ifdef LOCAL_DEFINE
  cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
  return 0;
}
