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

const int MAX = (int)2e5 + 123;
int b1[4 * MAX] = {}, b2[4 * MAX] = {};
int a[MAX];

void add(int b[], int l, int val, int N){
  for(int i = l; i <= N; i += (i & -i)){
    b[i] += val;
  }
}

void add_range(int l, int N){
  add(b1, l, 1, N);
  add(b2, l, (l - 1), N);
}

int get(int b[], int l){
  int total = 0;
  for(int i = l; i > 0; i -= (i & -i)){
    total += b[i];
  }
  return total;
}

int prefix_sum(int l){
  return get(b1, l) * l - get(b2, l);
}

int get_sum(int l){
  return prefix_sum(l) - prefix_sum(l - 1);
}

int check_Prime(int x){
  if(x < 2) return -1;
  for(int i = 2; i <= sqrt(x); ++i){
    if(x % i == 0) return -1;
  }
  return 1;
}

int powerMod(int a, int b, int mod){
  if(b == 1) return a;
  int x = powerMod(a, b / 2, mod) % mod;
  if(b&1){
    return (x * x) % mod * a % mod;
  } else {
    return (x * x) % mod;
  }
}

pair<int, int> decompose(int p){
  int i = 0;
  while(p % 2 == 0){
    ++i;
    p /= 2;
  }
  return {i, p};
}

bool witness(int a, int n){
  int k, m;
  tie(k, m) = decompose(n - 1);
  int x, y = powerMod(a, m, n);
  if(y == 1) return true;
  for1(i, k){
    x = (y * y) % n;
    if(x == 1){
      if(y == n - 1) return true;
      else return false;
    }
    y = x;
  }
  return false;
}

int millerRabinTesting(int n, int k){
  if(n < 2) return -1;
  if(n == 2 || n == 3) return 1;
  while(k--){
    int a = rand() % (n - 3) + 2;
    if(__gcd(a, n) != 1) return -1;
    if(powerMod(a, n - 1, n) != 1) return -1;
    if(!witness(a, n)) return -1;
  }
  return 1;
}

vi Primes;
const int MAX_SIEVE = sqrt((int)1e9) + 1;
bitset<MAX_SIEVE> bs;
void sieve(){
  bs.set();
  bs[0] = bs[1] = 0;
  Primes.pb(2);
  for(int i = 4; i < MAX_SIEVE; i += 2){
    bs[i] = 0;
  }
  for(int i = 3; i < MAX_SIEVE; i += 2){
    if(bs[i]){
      for(int j = i * i; j < MAX_SIEVE; j += i){
        bs[j] = 0;
      }
      Primes.pb(i);
    }
  }
}

int check_Sieve(int x){
  if(x < 2) return false;
  for(int i = 0; i < Primes.size() && Primes[i] * Primes[i] <= x; ++i){
    if(x % Primes[i] == 0){
      return -1;
    }
  }
  return 1;
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
  //sieve();
  int n;
  cin >> n;
  a[0] = 0;
  for1(i, n){
    int x;
    cin >> x;
    //x = check_Sieve(x);
    //x = millerRabinTesting(x, 5);
    x = check_Prime(x);
    a[i] = a[i - 1] + x;
  }
  const int N = n + 1;
  int total = 0;
  for(int i = n; i > 0; --i){
    add_range(a[i] + N + 1, 2 * N);
    total += n - i + 1 - get_sum(a[i - 1] + N);
  }
  cout << total << endl;
#ifdef LOCAL_DEFINE
  cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
  return 0;
}
