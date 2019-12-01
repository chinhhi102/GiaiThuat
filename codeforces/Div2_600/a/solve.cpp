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
  int T;
  cin >> T;
  while(T--){
  	int n;
    cin >> n;
    int a[n];
    int b[n];
    int x = 0;
    bool isf = true;
    bool lt = true;
	forn(i, n) cin >> a[i];
    forn(i, n) cin >> b[i];
    forn(i, n){
    	if(x){
    		if(b[i] - a[i] != 0){
    			a[i] += x;
    			continue;
			}else if(b[i] - a[i] != x)
				break;
		}
    	if(b[i] - a[i] != 0){
    		x = b[i] - a[i];
    		if(x < 0) break;
    		a[i] += x;
		}
	}
	forn(i, n){
		if(a[i] != b[i]) isf = false;
	}
	cout << (isf ? "YES" : "NO") << endl;
  }
  
#ifdef LOCAL_DEFINE
  cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
  return 0;
}
