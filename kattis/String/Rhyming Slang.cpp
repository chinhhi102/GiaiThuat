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

int main(){
	io;
	solve();
	return 0;
}

void solve(){
	string s;
	cin>>s;
	vector<string> ori;
	string tm="";
	fors(i,s.size(),0){
		tm=s[i]+tm;
		ori.pb(tm);
	}
	int n;
	cin>>n;
	cin.ignore();
	map<string,bool> m[n];
	fora(i,0,n){
		string tmp;
		getline(cin,tmp);
		istringstream iss(tmp);
		string t;
		while(iss>>t){
			m[i][t]=true;
		}
	}
	int mm;
	cin>>mm;
	cin.ignore();
	fora(i,0,mm){
		bool found=false;
		string tmp;
		getline(cin,tmp);
		string pas="";
		fors(j,tmp.size(),0){
			if(found)break;
			pas=tmp[j]+pas;
			fora(k,0,n){
				if(found)break;
				fora(l,0,ori.size()){
					if(m[k][pas]&&m[k][ori[l]]){
						found=true;
					}
				}
			}
		}
		if(!found)
			cout<<"NO";
		else
			cout<<"YES";
		cout<<endl;
	}
}
