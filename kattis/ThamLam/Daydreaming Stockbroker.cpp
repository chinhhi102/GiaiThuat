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
#define fora(i,a,b) for(int i=a;i<=b;i++)
#define fors(i,a,b) for(int i=a;i>=b;i--)
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

#define MAX 100000
ll money=100,stocks=0;
bool justbought;
void buy(ll price);
void sell(ll price);
void sell(ll price,ll amount);
int main(){
	ll days;scll(days);
	if(days==1){
		printf("%lld",money);
		return 0;
	}
	ll price;scll(price);
	fora(i,0,days-2){
		ll nextprice;scll(nextprice);
		if(nextprice>price){
			if(stocks==MAX||justbought){}
				else {
					buy(price);
					justbought=1;
				}
		}else if(nextprice<price){
			sell(price);
			justbought=0;
		}
		price=nextprice;
	}
	sell(price);
	printf("%lld",money);
    return 0;
}
void buy(ll price){
	ll leftOverMoney=money%price;
	stocks=money/price;
	money=leftOverMoney;
	if(stocks>MAX)sell(price,(stocks-MAX));
}
void sell(ll price){
	money+=price*stocks;
	stocks=0;
}
void sell(ll price,ll amount){
	money+=price*amount;
	stocks-=amount;
}
