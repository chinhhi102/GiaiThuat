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
int n,m,q;
string s[201];
int main(){
	io;
	solve();
	return 0;
}

void solve(){
	cin>>n>>m>>q;
	fora(i,0,n)
		cin>>s[i];
	string sq;
	int sz;
	fora(qs,0,q){
		cin>>sq;
		sz=sq.size();
		bool t1=1,t2=1,t3=1,t4=1,f=0;
		fora(i,0,n){
			if(f)break;
			fora(j,0,m){
				t1=t2=t3=1;
				if(f)break;
				if(j+sz>m){
					t1=0;
					t3=0;
					t4=0;
				}
				if(i+sz>n){
					t3=0;
					t2=0;
				}
				if(i-sz<0)
					t4=0;
				fora(k,0,sz){
					if(!(t1||t2||t3||t4))break;
					if(t1){
						if(s[i][j+k]!=sq[k])
							t1=0;
					}
					if(t2){
						if(s[i+k][j]!=sq[k])
							t2=0;
					}
					if(t3){
						if(s[i+k][j+k]!=sq[k])
							t3=0;
					}
					if(t4){
						if(s[i-k][j+k]!=sq[k])
							t4=0;
					}
				}
				if(t1||t2||t3||t4){
					cout<<i+1<<' '<<j+1<<' '<<(t1?1:t2?2:t3?3:4)<<endl;
					f=1;
				}
			}
		}
		if(!f)
			cout<<-1<<endl;
	}
}
