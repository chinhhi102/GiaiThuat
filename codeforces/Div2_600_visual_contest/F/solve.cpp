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

const int maxNod = (int)(1e5) + 5;
const int maxEdges = 3*(int)(1e5) + 5;
const int maxQueries = 3*(int)(1e5) + 5; 
const int maxTokens = 2*maxQueries; 
const i64 BIG = (i64)(1e9) * (i64)(1e9);

int nbNod, nbEdges, nbCentrals, nbQueries;
i64 rep[maxQueries];

// DSU

int dsuRepr[maxNod];
int dsuSize[maxNod];
vi tokenIn[maxNod];

int baseTok[maxTokens];

void dsuInit(){
  forn(nod, maxNod){
    dsuRepr[nod] = nod;
    dsuSize[nod] = 1;
  }
}

int dsuFind(int x){
  if(x != dsuRepr[x]){
    dsuRepr[x] = dsuFind(dsuRepr[x]);
  }
  return dsuRepr[x];
}

void dsuMerge(int small, int big, i64 curCap){
  small = dsuFind(small);
  big = dsuFind(big);
  if(small == big) return;
  if(dsuSize[small] > dsuSize[big]) swap(small, big);
  for(int token:tokenIn[small]){
    int oth = token ^ 1;
    int query = token / 2;
    if(dsuFind(baseTok[oth]) == big){
      rep[query] = curCap;
    }
    tokenIn[big].pb(token);
  }
  tokenIn[small].clear();
  tokenIn[small].shrink_to_fit();
  dsuSize[big] += dsuSize[small];
  dsuRepr[small] = big;
}

// Dijkstra

vector<pair<int, i64>> adj[maxNod];
i64 mdis[maxNod];

void dijkstra(){
  priority_queue<pair<i64, int>> pq;
  forn(nod, nbNod){
    if(nod < nbCentrals){
      pq.push({0, nod});
    } else {
      mdis[nod] = BIG;
    }
  }
  while(!pq.empty()){
    i64 dist;
    int nod;
    tie(dist, nod) = pq.top();
    dist = -dist;
    pq.pop();
    if(dist != mdis[nod]) continue;
    for(auto rawNeigh : adj[nod]){
      int neighbor = rawNeigh.first;
      i64 newDis = dist + rawNeigh.second;
      if(newDis < mdis[neighbor]){
        mdis[neighbor] = newDis;
        pq.push({-newDis, neighbor});
      }
    }
  }
}

struct Edge{
  i64 weigh, n1, n2;
  bool operator<(Edge &other){
    return weigh < other.weigh;
  }
};

vector<Edge> tabEdges;
 
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  cout.precision(10);
  cout << fixed;
#ifdef LOCAL_DEFINE
  freopen("input.txt","rt", stdin);
#endif
  dsuInit();
  cin >> nbNod >> nbEdges >> nbCentrals >> nbQueries;
  forn(iEdge, nbEdges){
    int n1, n2; 
    i64 weigh;
    cin >> n1 >> n2 >> weigh;
    --n1, --n2;
    adj[n1].emplace_back(n2, weigh);
    adj[n2].emplace_back(n1, weigh);
    tabEdges.push_back({weigh, n1, n2});
  }
  forn(query, nbQueries){
    int n1, n2;
    cin >> n1 >> n2;
    --n1, --n2;
    int tk1 = 2*query;
    int tk2 = 2*query + 1;
    baseTok[tk1] = n1;
    baseTok[tk2] = n2;
    tokenIn[n1].push_back(tk1);
    tokenIn[n2].push_back(tk2);
  }
  dijkstra();
  for(auto &edge:tabEdges){
    edge.weigh += mdis[edge.n1] + mdis[edge.n2];
  }
  sort(all(tabEdges));
  for(auto edge:tabEdges){
    dsuMerge(edge.n1, edge.n2, edge.weigh);
  }

  forn(query, nbQueries){
    cout << rep[query] << '\n';
  }
 
#ifdef LOCAL_DEFINE
  cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
  return 0;
}
