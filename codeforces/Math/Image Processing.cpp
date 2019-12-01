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

int main(){
	io;
	int h,w,n,m;
	cin>>h>>w>>n>>m;
	int a[h][w];
	fora(i,0,h){
		fora(j,0,w){
			cin>>a[i][j];
		}
	}
	int b[n][m];
	fora(i,0,n){
		fora(j,0,m){
			cin>>b[i][j];
		}
	}
	int c[h-n+1][w-m+1]={};
	fora(i,0,h-n+1){
		fora(j,0,w-m+1){
			fora(k,0,n){
				fora(l,0,m){
					c[i][j]+=a[i+k][j+l]*b[n-k-1][m-l-1];
				}
			}
		}
	}
	fora(i,0,h-n+1){
		fora(j,0,w-m+1)
			cout<<c[i][j]<<" ";
		cout<<endl;
	}
	return 0;
}
