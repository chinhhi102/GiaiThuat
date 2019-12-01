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
int dx[]={0,1,0,-1};
int dy[]={1,0,-1,0};
int n,sx,sy,ex,ey;
int grid[30][30],xline[20],yline[20];
void Try(int i,int j, int d){
    if(grid[i][j]==0 && i>=1 && i<=n && j>=1 && j<=n){
        grid[i][j]=1;
        xline[d]=i;
        yline[d]=j;
        if(i==ex && j==ey){
            cout<<d<<endl ;
       		for(int i=1;i<=d;i++)
            	cout<<xline[i]<<" "<<yline[i]<<endl;
        	exit(0);
        }else{
            d++;
            fora(k,0,4)
            	Try(i+dx[k],j+dy[k],d);
            d--;
        }
    }else return ;
}
int main(){
	io;
	cin>>n>>sx>>sy>>ex>>ey;
	fora(i,1,n+1)
		fora(j,1,n+1)
			cin>>grid[i][j];
	grid[sx][sy]=0;
	Try(sx,sy,1);
	cout<<0;
	return 0;
}
