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
string grid[101];
void solve();
int isstar(int x,int y,int d){
	int total=0;
	bool find=true;
	fora(k,x-d,x+d+1){
		fora(l,y-d,y+d+1)
			if(grid[k][l]!='*')
				find=false;
	}
	if(find)
		return d;
	else
		return 0;
}
int main(){
	io;
	solve();
	return 0;
}

void solve(){
	int n,m;
	cin>>n>>m;
	fora(i,0,n)
		cin>>grid[i];
	bool has[n][m]={};
	int count=0;
	fora(i,0,n){
		fora(j,0,m){
			if(grid[i][j]=='.')
				has[i][j]=1;
			else
				count++;
		}
	}
	int kt=0;
	vector<pair<pair<int,int>,int>> res;
	fora(i,1,n){
		fora(j,1,m){
			if(grid[i][j]=='.')continue;
			else{
				int len=min(min(i,n-i-1),min(j,m-j-1));
				fors(dm,len+1,1){
					int st=isstar(i,j,dm);
					cout<<i<<" "<<j<<" "<<dm<<endl;
					if(st==0)continue;
					res.pb({{i+1,j+1},st});
					fora(k,k-st,k+st+1){
						fora(l,k-st,l+st+1){
							cout<<k<<" "<<l<<endl;
							if(has[k][l]==0)
								kt++;
							has[k][l]=1;
						}
					}
				}
			}
		}
	}
	if(kt==count){
		cout<<res.size()<<endl;
		fora(i,0,res.size()){
			cout<<res[i].ff.ff<<" "<<res[i].ff.ss<<" "<<res[i].ss<<endl;
		}
	}else
		cout<<-1<<endl;
}
