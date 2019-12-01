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
int n,a[21],s=0;
vector<string> res;
bool kt(vector<bool> x);
void sol(){
	vector<bool> x(n);
	fora(i,0,n)
		x[i]=0;
	while(1){
		if(kt(x)){
			string temp="";
			fora(i,0,x.size())
				if(x[i])
					temp+='A';
				else
					temp+='B';
			res.pb(temp);
		}
		int p=n-1;
		while(p>=0&&x[p])p--;
		if(p==-1)break;
		x[p]=1;
		fora(i,p+1,n)
			x[i]=0;
//		fora(i,0,n)
//			cout<<x[i]<<' ';
//		cout<<endl;
	}
}
bool kt(vector<bool> x){
	int sum=0;
	fora(i,0,n)
		if(!x[i])
			sum+=a[i];
	if(sum*2==s)
		return 1;
	else
		return 0;
}
void backing(){
	
}

int main(){
	io;
	solve();
	return 0;
}

void solve(){
	cin>>n;
	fora(i,0,n){
		cin>>a[i];
		s+=a[i];
	}
	if(s%2)
		cout<<"khong chia duoc";
	else{
		sol();
		if(res.size()==0){
			cout<<"khong chia duoc";
		}else{
			cout<<res.size()<<endl;
			sort(all(res));
			fora(i,0,res.size()){
				fora(j,0,res[i].size()){
					cout<<res[i][j]<<' ';
				}
				cout<<endl;
			}
		}
	}
}
