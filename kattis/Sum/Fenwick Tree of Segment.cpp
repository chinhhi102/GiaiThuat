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
#define INF 1000000000000000000
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
#define MAXC 10000000
int n;
ll tree[MAXC]={};
void solve();
int sum(int a,int b);
void add(int k,int x);
int main(){
	io;
	solve();
	return 0;
}

void solve(){
	int q;
	cin>>n>>q;
	fora(i,0,q){
		char c;
		cin>>c;
		if(c=='+'){
			int ind,x;
			cin>>ind>>x;
			add(ind+1,x);
		}else{
			int ind;
			cin>>ind;
			cout<<sum(1,ind)<<endl;
		}
	}
}
int sum(int a,int b){
	a+=n;
	b+=n;
	int s=0;
	while(a<=b){
		if(a%2==1)s+=tree[a++];
		if(b%2==0)s+=tree[b--];
		a/=2;
		b/=2;
	}
	return s;
}
void add(int k, int x){
	k+=n;
	tree[k]+=x;
	for(k/=2;k>=1;k/=2){
		tree[k]=tree[2*k]+tree[2*k+1];
	}
}
