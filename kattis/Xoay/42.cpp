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
	int n,m;
	cin>>n>>m;
	int a[n*m];
	int res[n][m]={};
	int l=0,r=0;
	fora(i,0,n*m){
		cin>>a[i];
	}
	sort(a,a+n*m);
	int curr=0;
	bool up=true;
	while(1){
		res[l][r]=a[curr++];
		if(l==n-1&&r==m-1)break;
//		cout<<l<<" "<<r<<" "<<up<<endl;
		if(up){
			if(l-1<0||r+1>=m){
				if(r+1>=m){
					l++;
				}else{
					r++;
				}
				up=!up;
			}else{
				l--;
				r++;
			}
		}else{
			if(r-1<0||l+1>=n){
				if(l+1>=n){
					r++;
				}else{
					l++;
				}
				up=!up;
			}else{
				r--;
				l++;
			}
		}
	}
	fora(i,0,n){
		fora(j,0,m)
			cout<<res[i][j]<<" ";
		cout<<endl;
	}
}
/*
.
*/
