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

#define MAX (int)3e5

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  cout.precision(10);
  cout << fixed;
#ifdef LOCAL_DEFINE
  freopen("input.txt","rt", stdin);
#endif
  int a, b, c;
  cin >> a >> b >> c;
  int arr[a + b + c + 1] = {};
  int i = 1, x;
  for(; i <= a; i++){
  	cin >> x;
  	arr[x] = 1;
  }
  for(; i <= a + b; i++){
  	cin >> x;
  	arr[x] = 2;
  }
  for(; i <= a + b + c; i++){
  	cin >> x;
  	arr[x] = 3;
  }
  int result = 0;
  vector<int> arrB(a + b + c + 1, MAX);
  arrB[0] = -MAX;
  for(int i = 1; i <= a + b + c; i++){
  	int k = lower_bound(arrB.begin(), arrB.end(), arr[i] + 1) - arrB.begin();
  	arrB[k] = arr[i];
  	result = max(result, k);
  }
  cout << a + b + c - result << endl;
#ifdef LOCAL_DEFINE
  cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
  return 0;
}
