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
const string bases="!123456789abcdefghijklmnopqrstuvwxyz0";
void solve();
ll number_in_char(char c);
ll min_base(const string& num);
ll real_num(const string& num,ll base);
bool Try(ll a,ll b,ll ans,char op);
int main(){
	io;
	solve();
	return 0;
}

void solve(){
	int n;
	cin>>n;
	while(n--){
		string a,b,equals,ans;
		char op;
		cin>>a>>op>>b>>equals>>ans;
		bool valid=false;
		ll minBase=max(min_base(a),max(min_base(b),min_base(ans)));
		if(minBase){
			fora(base,minBase,37){
				ll ar=real_num(a,base);
				ll br=real_num(b,base);
				ll ansr=real_num(ans,base);
				if(!(ar&&br&&ansr))
					continue;
				if(Try(ar,br,ansr,op)){
					cout<<bases[base];
					valid=true;
				}
			}
			if(valid){
				cout<<endl;
				continue;
			}
		}
		cout<<"invalid"<<endl;
	}
}
bool Try(ll a,ll b,ll ans,char op){
	switch(op){
		case '+': return a+b==ans;
		case '-': return a-b==ans;
		case '*': return a*b==ans;
	}
	return ans*b==a;
}
ll number_in_char(char c){
	ll n=c;
	if(n<='9')
		return n-'0';
	return n-'a'+10;
}
ll min_base(const string& num){
	ll base=0;
	fora(i,0,num.size()){
		ll temp=number_in_char(num[i]);
		base=max(base,temp+1);
	}
	if(base==2)
		return 1;
	return base;
}
ll real_num(const string& num,ll base){
	ll res=0;
	ll pre_res=0;
	if(base==1){
		fora(i,0,num.size()){
			if(num[i]!='1')
				return 0;
			res++;
		}
		return res;
	}
	ll id=1;
	fors(i,num.size(),0){
		ll n=number_in_char(num[i]);
		res+=n*id;
		id*=base;
		if(pre_res>res)
			return 0;
		pre_res=res;
	}
	return res;
}
