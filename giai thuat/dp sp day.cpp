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

int main(){
	io;
	solve();
	return 0;
}

void solve(){
	int n,k;
	cin>>k>>n;
	int price[k][n];
	fora(i,0,k){
		fora(j,0,n)
			cin>>price[i][j];//san pham thu j ngay thu i
	}
	int total[1<<k][n]={};//gia nho nhat cua cua san pham s trong ngay thu d
	// total(s,d)=min(total(s,d-1),min(total(s\x,d-1)+price[x][d]))
	fora(x,0,k)
		total[1<<x][0]=price[x][0];//gia su neu chi co 1 ngay thi gia nho nhat la gia san pham ngay do
	fora(d,1,n)
		fora(s,0,(1<<k)){
			total[s][d]=total[s][d-1];
			fora(x,0,k){
				if(s&(1<<x)){
					total[s][d]=min(total[s][d],total[s^(1<<x)][d-1]+price[x][d]);
				}
			}
		}
	cout<<endl;
	fora(i,0,k){
		fora(j,0,n){
			cout<<total[1<<i][j]<<" ";
		}
		cout<<endl;
	}
}
/*
3 8
6 9 5 2 8 9 1 6
8 2 6 2 7 5 7 2
5 3 9 7 3 5 1 4
*/
