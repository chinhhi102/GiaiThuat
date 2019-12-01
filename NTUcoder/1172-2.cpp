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
class segment{
	private:
		vi st,A;
		int n;
		int left(int p){ return p<<1;}
		int right(int p){ return (p<<1)+1;}
		void build(int p,int l,int r){
			if(l==r)
				st[p]=l;
			else{
				build(left(p),l,(l+r)/2);
				build(right(p),(l+r)/2+1,r);
				int p1=st[left(p)],p2=st[right(p)];
				st[p]=(A[p1]<=A[p2])?p1:p2;
			}
		}
		int rmq(int p,int l,int r,int i,int j){
			if(i>r||j<l)return -1;
			if(i<=l&&r<=j)
				return st[p];
			int p1=rmq(left(p),l,(l+r)/2,i,j);
			int p2=rmq(right(p),(l+r)/2+1,r,i,j);
			if(p1==-1)
				return p2;
			if(p2==-1)
				return p1;
			return (A[p1]<=A[p2])?p1:p2;
		}
	public:
		segment(const vi &_A){
			A=_A;
			n=(int)A.size();
			st.assign(4*n,0);
			build(1,0,n-1);
		}
		int rmq(int i,int j){
			return rmq(1,0,n-1,i,j);
		}
};
int main(){
	io;
	solve();
	return 0;
}

void solve(){
	int n,q;
	cin>>n>>q;
	int a[n];
	fora(i,0,n)
		cin>>a[i];
	segment st(vi(a,a+n));
	int l,r;
	fora(i,0,q){
		cin>>l>>r;l--,r--;
		cout<<a[st.rmq(l,r)]<<endl;
	}
}
