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
#define sc(x) scanf("%d",&x)
#define scll(x) scanf("%lld",&x)
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
	int n,k;
	while(cin>>n){
		if(!n)break;
		cin>>k;
		vector<pair<int,int> > res(n+1,{0,0});
		fora(i,0,k){
			int p1,p2;
			string m1,m2;
			cin>>p1>>m1>>p2>>m2;
			if((m1[0]=='p'&&m2[0]=='r')||(m1[0]=='s'&&m2[0]=='p')||(m1[0]=='r'&&m2[0]=='s')){
				res[p1].ff++;
				res[p2].ss++;
			}
			if((m1[0]=='r'&&m2[0]=='p')||(m1[0]=='p'&&m2[0]=='s')||(m1[0]=='s'&&m2[0]=='r')){
				res[p1].ss++;
				res[p2].ff++;
			}
//			printf("%d %d %d %d\n",res[p1].ff,res[p1].ss,res[p2].ff,res[p2].ss);
		}
		fora(i,1,n+1){
			if (res[i].ff+res[i].ss == 0) printf("-\n");
			else
				printf("%.3f\n",res[i].ff*1.0/(res[i].ff+res[i].ss));
		}
		printf("\n");
	}
	return 0;
}
