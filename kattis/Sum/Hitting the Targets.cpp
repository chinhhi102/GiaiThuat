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
//typedef pair<int,int> pi;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<bool> vb;
typedef vector<vector<int> > vvi;
typedef map<int,int> mi;
typedef map<long,long> mll;
typedef pair<int,int> toaDo;
typedef pair<toaDo,toaDo> HCN;
typedef pair<toaDo,int> HT;
int main(){
	io;
	int n;
	cin>>n;
	vector<HCN> rec;
	vector<HT> cir;
	fora(i,0,n){
		string s;
		cin>>s;
		if(s.compare("circle")==0){
			int x,y,r;
			cin>>x>>y>>r;
			cir.pb(make_pair(make_pair(x,y),r));
		}else{
			int x1,y1,x2,y2;
			cin>>x1>>y1>>x2>>y2;
			rec.pb(make_pair(make_pair(x1,y1),make_pair(x2,y2)));
		}
	}
	int m;
	cin>>m;
	fora(i,0,m){
		int x,y;
		cin>>x>>y;
		int count=0;	
		fora(j,0,rec.size()){
			bool x1=x<=rec[j].ss.ff&&x>=rec[j].ff.ff;
			bool x2=y<=rec[j].ss.ss&&y>=rec[j].ff.ss;
			if(x1&&x2)
				count++;
		}
		fora(j,0,cir.size()){
			int x1=pow(x-cir[j].ff.ff,2);
			int x2=pow(y-cir[j].ff.ss,2);
			if(x1+x2<=pow(cir[j].ss,2))
				count++;
		}
		
		cout<<count<<endl;
	}
	return 0;
}
