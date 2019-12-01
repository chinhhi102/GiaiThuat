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
bool cmd(pair<int,int> x,pair<int,int> y){
	if(x.ff==y.ff)return x.ss>y.ss;
	return x.ff<y.ff;
}
int main(){
	io;
	int T;
	cin>>T;
	fora(k,1,T+1){
		map<int,int> count;
		vector<pair<int,int> > located;
		int n,e,p;
		cin>>n>>e>>p;
		fora(i,0,p){
			int x,y;
			cin>>x>>y;
			count[x]++;
			located.pb({x,y});
		}
		vector<int> ans;
		sort(located.begin(),located.end(),cmd);
		bool f=1;
		int num,j=0;
		fora(i,1,n+1){
			if(!count[i]){
				ans.pb(0);
				continue;
			}
			int len=count[i];
			num=0;
			while(len>0&&f){
				for(;j<located.size()&&len>0;j++){
					if(located[j].ff==e){
						num=0;
						len=0;
						while(located[j+1].ff==e)
							j++;
					}
					else if(located[j].ff==i){
						num++;
						len-=located[j].ss;
						if(len<0)len=0;
						if(located[j].ss==0)
							if(len>0)
								len=-1;
					}
					else if(located[j].ff>i){
						if(len>0)
							len=-1;
					}
				}
			}
			if(len<0) f=0;
				else ans.pb(num);	
		}
		if(f){
			cout<<"Case #"<<k<<": ";
			fora(i,0,ans.size())
				cout<<ans[i]<<" ";
		}else
			cout<<"Case #"<<k<<": "<<"IMPOSSIBLE";
		cout<<endl;
	}
	return 0;
}
