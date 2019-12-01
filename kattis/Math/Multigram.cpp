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

int main(){
	io;
	string s;
	cin>>s;
	map<char,int> temp;
	map<char,int> form;
	int k=s.size();
	for(int i=1;i<=k/2;i++){
		temp[s[i-1]]++;
		bool res=1;
		if(k%i){
			continue;
		}
		for(int l=0;l<k/i-1;l++){
			fora(j,1,i+1){
				form[s[l*i+j+i-1]]++;
			}
			bool f=1;
			if(temp.size()!=form.size()){
				form.clear();
				res=0;
				break;
			}
			for(map<char,int>::iterator it=temp.begin();it!=temp.end();it++){
				if(it->ss!=form[it->ff]){
					f=0;
					break;
				}
			}
			if(f){
				form.clear();
				continue;
			}
			else{
				form.clear();
				res=0;
				break;
			}
		}
		if(res){
			fora(j,0,i)
				cout<<s[j];
			return 0;
		}
	}
	cout<<-1;
	return 0;
}
