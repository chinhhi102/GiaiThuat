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
#include <list>
#include <stack>
#include <iterator>
#include <complex>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
using namespace std;

#define io ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define fora(i,a,b) for(int i=a;i<b;i++)
#define fors(i,a,b) for(int i=a-1;i>=b;i--)
#define men(a) menset(a,0,sizeof(a))
#define sc(x) scanf("%d",&x);
#define scll(x) scanf("%lld",&x);
#define c1(a) cin>>a
#define c2(a,b) cin>>a>>b
#define c3(a,b,c) cin>>a>>b>>c
#define pb push_back
#define ff first
#define ss second
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

int main(){
	int cases;
	sc(cases);
	printf("%d\n",cases);
	cin.ignore();
	fora(k,0,cases){
		string c;
		c1(c);
		int p[2];
		p[0]=0;
		p[1]=0;
		vector<pair<int,int> > path;
		int change=0;
		int max_x=0;
		int max_y=0;
		int min_y=0;
		for(int i=0;i<c.size();i++){
			if(c[i]=='L') change=(change+3)%4;
			else if(c[i]=='R') change=(change+1)%4;
			else if(c[i]=='B') change=(change+2)%4;
		
			if(change==0)p[0]++;
			else if(change==1)p[1]++;
			else if(change==2)p[0]--;
			else if(change==3)p[1]--;
	
			path.push_back(make_pair(p[0],p[1]));
	
			max_x=max(max_x,p[0]);
			max_y=max(max_y,p[1]);
			min_y=min(min_y,p[1]);
		}
		int w=max_x+2;
		int h=max_y-min_y+3;
		printf("%d %d\n",h,w);
//		fora(it,0,path.size()) printf("%d-%d\n",path[it].ff,path[it].ss);
		fora(i,min_y-1,max_y+2){
			fora(j,0,w){
				int f=0;
				fora(it,0,path.size()) if(j==path[it].ff&&i==path[it].ss){f=1;break;}
				printf(f?".":"#");
			}
			printf("\n");
		}
	}
	return 0;
}
