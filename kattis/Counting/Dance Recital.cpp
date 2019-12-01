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
//#include <tuple>
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
int dist(string a,string b){
	int total=0;
	vector<bool> na(26);
	vector<bool> nb(26);
	fora(i,0,a.size()){
		na[a[i]-'A']=1;
	}
	fora(i,0,b.size()){
		nb[b[i]-'A']=1;
	}
	fora(i,0,26)
		if(na[i]&&nb[i])
			total++;
	return total;
}
int findbest(vector<vi >& dis,vi& pe){
	int total=0;
	fora(i,1,pe.size()){
		total+=dis[pe[i]][pe[i-1]];
	}
	return total;
}
int main(){
	io;
	int n;
	cin>>n;
	vector<string> v(n);
	fora(i,0,n){
		cin>>v[i];
	}
	vector<vi > dis(n,vi(n));
	fora(i,0,n){
		fora(j,i+1,n){
			dis[i][j]=dist(v[i],v[j]);
			dis[j][i]=dis[i][j];
		}
	}
	vector<int> pe(n);
	fora(i,0,n)
		pe[i]=i;
	int best=1001;
	do{
		best=min(best,findbest(dis,pe));
	}while(next_permutation(pe.begin(),pe.end()));
	cout<<best;
	return 0;
}
