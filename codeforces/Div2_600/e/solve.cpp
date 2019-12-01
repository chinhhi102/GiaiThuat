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

const int maxn = 2e5 + 50;
int dp[maxn];
int n, m;
struct node{
    int x, r;
    bool operator < (const node& a) const{return x < a.x;}
}e[100];

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  cout.precision(10);
  cout << fixed;
#ifdef LOCAL_DEFINE
  freopen("input.txt","rt", stdin);
#endif

memset(dp, 0x3f, sizeof dp);
    dp[0] = 0;
	cin>>n>>m;
	for(int i = 0; i < n; ++i) scanf("%d%d", &e[i].x, &e[i].r);
	sort(e, e+n);
	for(int i = 0; i < n; ++i){
        for(int j = 0; j + e[i].x + e[i].r <= 2*m; ++j){
            int pre = e[i].x - e[i].r - j - 1;
            if(pre < 0) pre = 0;
            dp[e[i].x + e[i].r + j] = min(dp[e[i].x + e[i].r + j], dp[pre] + j);
			forn(i, 2*m) cout << dp[i] << ' ';cout << endl;
        }
        for(int j = 2*m-1; j >= 0; --j) dp[j] = min(dp[j], dp[j+1]);
	}
	cout<<dp[m]<<endl;

#ifdef LOCAL_DEFINE
  cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
  return 0;
}
/*
5 10
6 2
3 1
4 3
9 4
10 5
0
*/
