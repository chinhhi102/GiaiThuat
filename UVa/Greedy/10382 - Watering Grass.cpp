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
typedef struct{
	double l,r;
}co;
bool cmd(co x,co y){
	if(x.l==y.l)
		return x.r>y.r;
	return x.l<y.l;
}
int main(){
	io;
	solve();
	return 0;
}

void solve(){
	int n,l,w;
	while(cin>>n>>l>>w){
		vector<co> D;
		fora(i,0,n){
			double x,r;
			cin>>x>>r;
			if(r>w/2.0){
				double cover=sqrt(r*r-(w/2.0)*(w/2.0));
				D.pb({x-cover,x+cover});
			}
		}
		sort(all(D),cmd);
		int m=D.size();
		int ch,flag=0;
		double right=0;
		for(int i=0,j=0;i<m;i++){
			double tmp=right;
			ch=-1;
			while(j<m&&D[j].l<=right){
				if(D[j].r>tmp){
					tmp=D[j].r;
					ch=j;
				}
				j++;
			}
			if(tmp>=l){
				cout<<i+1<<endl;
				flag=1;
				break;
			}
			if(ch==-1){
				break;
			}
			right=tmp;
		}
		if(!flag)
			cout<<-1<<endl;
	}
}
