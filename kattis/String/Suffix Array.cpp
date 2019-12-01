#ifndef competitive_programming_H
#define competitive_programming_H
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
#include <tuple>
#include <ctype.h>
#include <stack>
#include <iterator>
#include <complex>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <functional>
#include <time.h>
#include <unordered_map>
#include <unordered_set>
#include <functional>
using namespace std;

#define io ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
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
#define UNIQUE(c) (c).resize(unique(all(c))-(c).begin())
#define debug freopen("D:\\baiTapLapTrinh\\UVa\\out.txt","w",stdout);
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
#endif
void solve();

#define MAX_N 100010
char T[MAX_N];
int SA[MAX_N], tempSA[MAX_N];
int RA[MAX_N], tempRA[MAX_N], c[MAX_N], n;	// c for counting/radix sort
void countingSort(int k){
  int i, sum, maxi = max(300, n);	// up to 255 ASCII chars or length of n
  memset(c, 0, sizeof c);				// clear frequency table
  for (i = 0; i < n; i++)	// count the frequency of each interger rank
  	c[i + k < n ? RA[i + k] : 0]++;
  for (i = sum = 0; i < maxi; i++){
  	int t = c[i]; c[i] = sum; sum += t;}
  for (i = 0; i < n; i++)			// shuffle the suffix array if necessary
  	tempSA[c[SA[i]+k < n ? RA[SA[i]+k] : 0]++] = SA[i];
  for (i = 0; i < n; i++)		// update the suffix array SA
    SA[i] = tempSA[i];
}
void constructSA(){	// this version can go up to 100000 characters
  int i, k ,r;
  for(i = 0; i < n; i++) RA[i] = T[i];		// initial rankings
  for(i = 0; i < n; i++) SA[i] = i;	// initial SA
  for(k = 1; k < n; k<<=1) {	// repeat sorting process log n time
  	countingSort(k);		// actually radix sort: sort based on the second times
  	countingSort(0);	// then (stable) sort based on the first item
  	tempRA[SA[0]] = r = 0;		// re-ranking: start from rank r = 0
  	for ( i = 1; i < n; i++)	// compare adjacent suffixes
  	  tempRA[SA[i]] = 	// if same pair => same rank r; otherwise, increase r
  	  (RA[SA[i]] == RA[SA[i-1]] && RA[SA[i]+k] == RA[SA[i-1]+k]) ? r : ++r;
  	for (i = 0; i < n; i++)		// update the rank array RA
  	  RA[i] = tempRA[i];
  	if (RA[SA[n-1]] == n-1)break;	// nice optimization trick
  }
}
int main(){
	io;
	solve();
	return 0;
}

void solve(){
	n = (int)strlen(gets(T));
	T[n++] = '$';
	constructSA();
	fora(i,0,n)
		printf("%2d\t%s\n",SA[i],T+SA[i]);
}
