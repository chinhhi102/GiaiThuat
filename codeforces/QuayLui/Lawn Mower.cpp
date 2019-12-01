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
bool kt(vector<double>& v, double mover){
	fora(i,0,v.size()-1){
		if(v[i+1]-v[i]>mover)
			return 0;
	}
	return 1;
}
int main(){
	io;
	int nx,ny;
	double mover;
	while(cin>>nx>>ny>>mover&&nx!=0&&ny!=0){
		vector<double> leng,wigh;
		fora(i,0,nx){
			double temp;
			cin>>temp;
			wigh.pb(temp);
		}
		fora(i,0,ny){
			double temp;
			cin>>temp;
			leng.pb(temp);
		}
		sort(leng.begin(),leng.end());
		sort(wigh.begin(),wigh.end());
		bool l=0,w=0;
		if(kt(leng,mover)&&leng[0]<=mover/2&&leng[ny-1]>=100-mover/2)
			l=1;
		if(kt(wigh,mover)&&wigh[0]<=mover/2&&wigh[nx-1]>=75-mover/2)
			w=1;
		if(l&&w)
			cout<<"YES\n";
		else
			cout<<"NO\n";
	}
	return 0;
}
