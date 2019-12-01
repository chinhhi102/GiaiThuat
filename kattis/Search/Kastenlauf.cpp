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
#include <iomanip>
#include <list>
//#include <tuple>
#include <ctype.h>
#include <stack>
#include <iterator>
#include <complex>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <functional>
#include <time.h>
//#include <unordered_map>
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
#define all(x) (x).begin(), (x).end()
#define M_PI 3.14159265358979323846
#define fix(x) cout<<fixed<<setprecision(x)
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
int union_find[110];
vector<pair<int, int> > points;
int find(int a) {
  if(union_find[a] == a) return a;
  return union_find[a] = find(union_find[a]);
}
void merge(int a, int b) {
  union_find[find(a)] = find(b);
}

int main(){
	io;
	int T; cin >> T;
	while(T--) {
    	int N; cin >> N;
    	points.resize(N + 2);
    	for(int i = 0; i < (N + 2); i++) {
      		cin >> points[i].first >> points[i].second;
      		union_find[i] = i;
    	}
    	for(int i = 0; i <= N; i++) {
      		for(int j = 0; j < (N + 2); j++) {
        		if(i == j) continue;
        		if(abs(points[j].first - points[i].first) + abs(points[j].second - points[i].second) <= 1000) {
          			merge(i, j);
        		}
      		}
    	}
    	if(find(0) == find(N + 1)) cout << "happy" << endl;
    	else cout << "sad" << endl;
  	}
	return 0;
}
