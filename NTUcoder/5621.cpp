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
//	solve();
	solve2();
	return 0;
}

void solve(){
	string x,y;
	cin>>x>>y;
	string minr="",maxr="";
	int i=0,j=0;
	while(i<x.size()||j<y.size()){
		if(i>=x.size()){
			while(j<y.size()){
				minr+=y[j++];
			}
		}else if(j>=y.size()){
			while(i<x.size()){
				minr+=x[i++];
			}
		}else if(x[i]==y[j]){
			int k=i,l=j;
			while(x[k]==y[l]){
				if(k+1==x.size()){
					if(l+1==y.size())
						break;
					else
						l++;
					k=i;
				}else if(l+1==y.size()){
					if(k+1==x.size())
						break;
					else
						k++;
					l=j;
				}else{
					k++;
					l++;
				}
			}
			if(x[k]>y[l]){
				minr+=y[j++];
			}else
				minr+=x[i++];
		}else{
			if(x[i]>y[j]){
				minr+=y[j++];
			}else
				minr+=x[i++];
		}
	}
	i=0,j=0;
	while(i<x.size()||j<y.size()){
		if(i>=x.size()){
			while(j<y.size()){
				maxr+=y[j++];
			}
		}else if(j>=y.size()){
			while(i<x.size()){
				maxr+=x[i++];
			}
		}else if(x[i]==y[j]){
			int k=i,l=j;
			while(x[k]==y[l]){
				if(k+1==x.size()){
					if(l+1==y.size())
						break;
					else
						l++;
					k=i;
				}else if(l+1==y.size()){
					if(k+1==x.size())
						break;
					else
						k++;
					l=j;
				}else{
					k++;
					l++;
				}
			}
			if(x[k]<y[l]){
				maxr+=y[j++];
			}else
				maxr+=x[i++];
		}else{
			if(x[i]<y[j]){
				maxr+=y[j++];
			}else
				maxr+=x[i++];
		}
	}
	cout<<minr<<endl<<maxr;
}
void solve2(){
	string a,b;
	cin>>a>>b;
	string x=a,y=b;
	string h="";
	while(x!=""&&y!=""){
		if(x+y<y+x){
			h+=x[0];
			x.erase(0,1);
		}else{
			h+=y[0];
			y.erase(0,1);
		}
	}
	cout<<h+x+y<<endl;
	h="";
	while(a!=""&&b!=""){
		if(a+b<b+a){
			h+=b[0];
			b.erase(0,1);
		}else{
			h+=a[0];
			a.erase(0,1);
		}
	}
	cout<<h+a+b<<endl;
}
