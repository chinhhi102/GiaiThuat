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
#define MOD 1000000007
int main(){
//	io;
	ll n,t,a,b,c,tg;
	std::cin>>n>>t>>a>>b>>c>>tg;
	std::vector<ll> times;
	times.pb(tg);
	fora(i,0,n-1)
		times.pb((a*times[(times.size()-1)]+b)%c+1);
	std::sort(times.begin(),times.end());
	ll sol=0,ti=0,cur=t;
	for(int tim=0;tim<times.size();tim++){
		if(cur<times[tim])
			break;
		cur-=times[tim];
		sol++;
		ti+=(t-cur);
		t%=MOD;
	}
	std::cout<<sol<<" "<<ti%MOD;
	return 0;
}
