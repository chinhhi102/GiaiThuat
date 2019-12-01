#include <map>
#include <set>
#include <queue>
#include <cmath>
#include <vector>
#include <cstdio>
#include <bitset>
#include <cstring>
#include <cstdlib>
#include <complex>
#include <iostream>
#include <algorithm>
#include <math.h>
#include <list>
#include <stack>
#include <iterator>
#include <complex>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
using namespace std;

#define io ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define fora(i,a,b) for(int i=a;i<b;i++)
#define fors(i,a,b) for(int i=a-1;i>=b;i--)
#define men(a) menset(a,0,sizeof(a))
#define sc(x) scanf("%d",&x)
#define scll(x) scanf("%lld",&x)
#define c1(a) cin>>a
#define c2(a,b) cin>>a>>b
#define c3(a,b,c) cin>>a>>b>>c
#define pb push_back
#define ff first
#define ss second
#define M_PI 3.14159265358979323846
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pi;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<bool> vb;
typedef vector<vector<int> > vvi;
typedef map<int,int> mi;
typedef map<long,long> mll;
double cranes[30][2];
vector<int> walls[4];
vector<int> reaching[30];

int main(){
	io;
	int n; double l, w, r; cin >> l >> w >> n >> r;

  for(int i = 0; i < n; i++) cin >> cranes[i][0] >> cranes[i][1];

  for(int i = 0; i < n; i++) {
    double x1 = cranes[i][0], y1 = cranes[i][1], x2 = -l/2, y2 = 0;
    if(sqrt(pow(x1 - x2, 2.0) + pow(y1 - y2, 2.0)) <= r) walls[0].push_back(i);

    x1 = cranes[i][0], y1 = cranes[i][1], x2 = l/2, y2 = 0;
    if(sqrt(pow(x1 - x2, 2.0) + pow(y1 - y2, 2.0)) <= r) walls[1].push_back(i);

    x1 = cranes[i][0], y1 = cranes[i][1], x2 = 0, y2 = -w/2;
    if(sqrt(pow(x1 - x2, 2.0) + pow(y1 - y2, 2.0)) <= r) walls[2].push_back(i);

    x1 = cranes[i][0], y1 = cranes[i][1], x2 = 0, y2 = w/2;
    if(sqrt(pow(x1 - x2, 2.0) + pow(y1 - y2, 2.0)) <= r) walls[3].push_back(i);
  }

  int ans = 4;
  if(walls[0].size() == 0 || walls[1].size() == 0 || walls[2].size() == 0 || walls[3].size() == 0) {
    ans = -1;
  }
  else {
    for(int i = 0; i < n; i++) {
      for(int j = 0; j < 4; j++) {
        if(binary_search(walls[j].begin(), walls[j].end(), i)) reaching[i].push_back(j);
      }
    }

    set<int> temp;
    for(int i = 0; i < n; i++) {
      if(reaching[i].size() == 4) ans = min(ans, 1);

      for(int j = 0; j < n; j++) {
        temp.clear();
        for(auto it: reaching[i]) temp.insert(it);
        for(auto it: reaching[j]) temp.insert(it);
        if(temp.size() == 4) ans = min(ans, 2);

        for(int k = 0; k < n; k++) {
          temp.clear();
          for(auto it: reaching[i]) temp.insert(it);
          for(auto it: reaching[j]) temp.insert(it);
          for(auto it: reaching[k]) temp.insert(it);
          if(temp.size() == 4) ans = min(ans, 3);
        }
      }
    }
  }

  if(ans == -1) cout << "Impossible" << endl;
  else cout << ans << endl;
	return 0;
}
