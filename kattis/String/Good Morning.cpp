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
string rev(string a){
	string b="";
	fors(i,a.size(),0)
		b+=a[i];
	return b;
}
string to_string(int a){
	string ans="";
	while(a>0){
		ans+=a%10+'0';
		a/=10;
	}
	return rev(ans);
}
int main(){
	io;
	map<char,int> xx;
	map<char,int> yy;
	xx['1']=0;
	xx['2']=1;
	xx['3']=2;
	xx['4']=0;
	xx['5']=1;
	xx['6']=2;
	xx['7']=0;
	xx['8']=1;
	xx['9']=2;
	xx['0']=1;
	
	yy['1']=0;
	yy['2']=0;
	yy['3']=0;
	yy['4']=1;
	yy['5']=1;
	yy['6']=1;
	yy['7']=2;
	yy['8']=2;
	yy['9']=2;
	yy['0']=3;
	set<int> poss;
	fora(i,1,201){
		string s=to_string(i);
//		cout<<s<<endl;
		bool m=true;
		fora(j,1,s.size()){
//			cout<<xx[s[j]]<<" "<<xx[s[j-1]]<<'\t'<<yy[s[j]]<<" "<<yy[s[j-1]]<<endl;
			if(xx[s[j]]<xx[s[j-1]]||yy[s[j]]<yy[s[j-1]])
				m=false;
		}
		if(m){
			poss.insert(i);
//			cout<<i<<" ";
		}
	}
	int n;
	cin>>n;
	fora(i,0,n){
		int s;
		cin>>s;
		if(poss.count(s)>0){
			cout<<s<<endl;
			continue;
		}
		int j=1;
		while(1){
			if(poss.count(s-j)>0){
				cout<<s-j<<endl;
				break;
			}
			if(poss.count(s+j)>0){
				cout<<s+j<<endl;
				break;
			}
			j++;
		}
	}
	return 0;
}
