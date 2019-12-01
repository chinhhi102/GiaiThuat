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
	int r,s,K;
	cin>>r>>s>>K;
	string pic[r];
	fora(i,0,r){
		cin>>pic[i];
	}
	int res=0,idx,idy;
	fora(i,0,r-K+1){
		fora(j,0,s-K+1){
			int fi=0;
			fora(k,i+1,i+K-1){
				fora(l,j+1,j+K-1){
					if(pic[k][l]=='*')
						fi++;
				}
			}
			if(fi>res){
				res=fi;
				idx=i;
				idy=j;
			}
		}
	}
	cout<<res<<endl;
	fora(i,0,r){
		fora(j,0,s){
			if(!((i==idx)||(i==idx+K-1)||(j==idy)||(j==idy+K-1))){
				cout<<pic[i][j];
			}else{
				if(((i==idx)&&(j==idy))||((i==idx)&&(j==idy+K-1))||((i==idx+K-1)&&(j==idy))||((i==idx+K-1)&&(j==idy+K-1)))
					cout<<'+';
				else{
					if((i==idx&&(j>=idy&&j<idy+K))||(i==idx+K-1&&(j>=idy&&j<idy+K)))
						cout<<'-';
					else if((j==idy&&i>=idx&&i<idx+K)||(j==idy+K-1&&i>=idx&&i<idx+K))
						cout<<'|';
					else
						cout<<pic[i][j];
				}
			}
		}
		cout<<endl;
	}
}
