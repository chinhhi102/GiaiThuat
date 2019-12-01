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

void solve();
void solve2();
int main(){
	io;
	solve();
//	solve2();
	return 0;
}

void solve(){
//	freopen("D:\\Download\\Compressed\\SORT\\03.in","r",stdin);
//	ll m[500000]={};
	int n;
	cin>>n;
	int res=1;
	int *X=(int*)malloc(1000000*sizeof(int));
//	vector<short> X(n+1,0);
	fora(i,0,n){
		int x;
		cin>>x;
		if(X[x-1]==0)
			X[x]=1;
		else{
			X[x]=X[x-1]+1;
			if(X[x]>res)
				res=X[x];
		}
	}
	free(X);
	cout<<n-res<<endl;
//		cin>>X[i];
//	vector<int> P(n);
//	vector<int> M(n+1);
//	int L=0;
//	fora(i,0,n){
//		int lo=1;
//		int hi=L;
//		while(lo<=hi){
//			int mid=(lo+hi)/2;
//			if(X[M[mid]]<X[i])
//				lo=mid+1;
//			else
//				hi=mid-1;
//		}
//		int newL=lo;
//		P[i]=M[newL-1];
//		M[newL]=i;
//		if(newL>L){
//			L=newL;
//		}
//	}
//	cout<<n-res<<endl;
}
void solve2(){
//	freopen("D:\\Download\\Compressed\\SORT\\00.in","r",stdin);
	int n;
	cin>>n;
	vector<int> data(n+1);
	fora(i,1,n+1){
		cin>>data[i];
	}
	sort(data.begin()+1,data.end());
	fora(i,1,n+1)
		cout<<data[i]<<" ";
}
