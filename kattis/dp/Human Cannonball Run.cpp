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
#define fix(x) cout<<fixed<<setprecision(x)
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
typedef map<long,long> mll;

double  mp[200][200];
struct node{
   double x, y; 
};
int n;
double dis(double x1,double x2,double y1,double y2){return sqrt((x1-y1)*(x1-y1) + (x2-y2)*(x2-y2));}
double mi;
int main(){
	io;
	node be,en,dapao[200];
	cin>>be.x>>be.y>>en.x>>en.y;
    mi=dis(be.x,be.y,en.x,en.y)/5;
    cin>>n;
    dapao[n].x = en.x ; 
    dapao[n].y = en.y ;
    fora(i,0,n)
    	cin>>dapao[i].x>>dapao[i].y;
    fora(i,0,n)
       fora(j,0,n+1){
          double  tmp;
          mp[i][j] = dis(dapao[i].x,dapao[i].y,dapao[j].x,dapao[j].y);
          tmp = 2 + fabs(50.0 - mp[i][j])/5 ;
          mp[i][j] = min(mp[i][j]/5,tmp);
       }
    fora(k,0,n)
      fora(i,0,n)
        fora(j,0,n+1)
		    mp[i][j] = min(mp[i][j],mp[i][k] + mp[k][j]);
    fora(i,0,n)
         mi = min(mi,dis(be.x,be.y,dapao[i].x,dapao[i].y)/5+mp[i][n]);
    fix(7);
    	cout<<mi;
	return 0;
}
