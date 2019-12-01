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
int n,m,sx,sy;
string grid[30];
string mapp[30];
pair<vector<int>,vector<int>> path;
vector<vector<bool>> vis;
vector<int> xline(20),yline(20);
int houses=0;
int dmax=1e9;
ull coun=0;
vector<bool> valid(4,false);
void Try(int i,int j,int d){
	coun++;
	cout<<i<<" "<<j<<" "<<d<<" "<<coun<<endl;
    if(i>=1&&i<=n&&j>=1&&j<=m){
    	if(grid[i][j]!='#'){
    		vis[i][j]=true;
    		bool us=false;
    		bool ush=false;
    		if(grid[i][j]=='o'){
    			grid[i][j]='.';
   		 		xline[d]=i;
   		     	yline[d]=j;
    	   		d++;
       			us=true;
			}
			if(grid[i][j]=='A'||grid[i][j]=='B'||grid[i][j]=='C'||grid[i][j]=='D'){
				if(valid[grid[i][j]-'A']){
					valid[grid[i][j]-'A']=false;
					houses--;
					if(!houses){
						houses++;
						if(d<dmax){
							dmax=d;
							path={xline,yline};
							return;
						}
					}
					ush=true;
				}
			}
       		fora(k,0,4){
        		if(!vis[i+dx[k]][j+dy[k]])
        			Try(i+dx[k],j+dy[k],d);
			}
			if(us){
				grid[i][j]='.';
				d--;
			}
			if(ush){
				valid[grid[i][j]-'A']=true;
				houses++;
			}
			if(i!=sx&&j!=sy)
				vis[i][j]=false;
		}
    }
}
void solve();
int main(){
	io;
	solve();
	return 0;
}
void solve(){
	freopen("D:\\baiTapLapTrinh\\test\\doan\\path.out","w",stdout);
	while(cin>>m>>n&&n!=0){
		vis.clear();
		houses=0;
		dmax=1e9;
		coun=0;
		xline.clear();
		yline.clear();
		vis.resize(n+2,vector<bool>(m+2,false));
		fora(i,1,n+1){
			mapp[i].clear();
			grid[i].clear();
			cin>>grid[i];
			mapp[i]=grid[i];
		}
		fora(i,1,n+1){
			grid[i]=" "+grid[i];
			mapp[i]=" "+mapp[i];
			fora(j,1,m+1){
				if(grid[i][j]=='A'||grid[i][j]=='B'||grid[i][j]=='C'||grid[i][j]=='D'){
					valid[grid[i][j]-'A']=true;
					houses++;
					sx=i;
					sy=j;
				}
			}
		}
		vis[sx][sy]=true;
		Try(sx,sy,1);
		fora(i,0,path.ff.size()){
			mapp[path.ff[i]][path.ss[i]]='.';
		}
		cout<<m<<" "<<n<<endl;
		fora(i,1,n+1){
			fora(j,1,m+1)
				cout<<mapp[i][j];
			cout<<endl;
		}
		cout<<endl;
	}
}
