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

class UnionFind{
	private:
		vi p,rank,ma,mi;
		int n;
	public:
		UnionFind(int N){
			n = N - 1;
			p.assign(N,0);
			rank.assign(N,0);
			ma.assign(N,0);
			mi.assign(N,0);
			forn(i,N){
				p[i]=i;
				ma[i]=i;
				mi[i]=i;
			}				
		}
		int findSet(int i){
			return (p[i]==i)?i:(p[i]=findSet(p[i]));
		}
		bool isSameSet(int i,int j){
			return findSet(i)==findSet(j);
		}
		void unionSet(int i,int j){
			if(!isSameSet(i,j)){
				int x=findSet(i);
				int y=findSet(j);
				if(rank[x]>rank[y]){
					p[y]=x;
					ma[x]=max(ma[y],ma[x]);
					mi[x]=min(mi[y],mi[x]);
				}
				else{
					p[x]=y;
					rank[y]+=(rank[x]==rank[y]);
					ma[y]=max(ma[y],ma[x]);
					mi[y]=min(mi[y],mi[x]);
				}
			}
		}
		void cal(){
			map<int,int> m;
			for1(i, n){
				int x = findSet(i);
				m[mi[x]]=1;
				m[ma[x]]=-1;
				if(mi[x] == ma[x]) m[mi[x]] = 0; 
			}
			int total = 0;
			int cur = 0;
			for(auto i:m){
				cur += i.second;
				if(i.second == 0) ++cur;
				if(cur > 1 && i.second >= 0)
				  total++;
				if(i.second == 0) --cur;
			}
			cout << total << endl;
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
  UnionFind UF(n + 1);
  forn(i, m){
  	int x, y;
  	cin >> x >> y;
  	UF.unionSet(x, y);
  }
  UF.cal();
#ifdef LOCAL_DEFINE
  cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
  return 0;
}
/*
14 1
1 2
*/
