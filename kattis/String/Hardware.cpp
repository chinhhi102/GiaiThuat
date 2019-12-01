#ifndef competitive_programming_H
#define competitive_programming_H
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
#define UNIQUE(c) (c).resize(unique(all(c))-(c).begin())
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
#endif
void solve();
void extra(int digit[],int x){
	digit[x%10]++;
	while(x/=10)
		digit[x%10]++;
}
int main(){
	io;
	solve();
	return 0;
}

void solve(){
	int n;
	scanf("%d\n",&n);
	while(n--){
		int digit[10]={};
		char s[51],add[51];
		fgets(s,50,stdin);
//		printf("%d\n",strlen(s));
		int k;
		scanf("%d %s\n",&k,&add);
		int re=k;
		while(k){
			char line[100];
			fgets(line,50,stdin);
			if(line[0]=='+'){
				char p;
				int st,se,jp;
				sscanf(line,"%c %d %d %d\n",&p,&st,&se,&jp);
				for(int i=st;i<=se;i+=jp){
					k--;
					extra(digit,i);
				}
			}else{
				int a;
				sscanf(line,"%d\n",&a);
				extra(digit,a);
				k--;
			}
		}
		int total=0;
		printf("%s%d %s\n",s,re,add);
		fora(i,0,10){
			printf("Make %d digit %d\n",digit[i],i);
			total+=digit[i];
		}
		printf("In total %d digit%s",total,total==1?"\n":"s\n");
	}
}
