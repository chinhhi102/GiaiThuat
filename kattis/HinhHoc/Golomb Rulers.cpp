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

int main(){
	io;
	string s;
	while(getline(cin,s)){
		istringstream iss(s);
		map<int,bool> m;
		int b[26];
		int n=0;
		bool f=1;
		while(iss>>b[n++]);n--;
		sort(b,b+n);
		for(int i=0;i<n;i++){
			for(int j=i-1;j>=0&&f;j--){
				if(m[b[i]-b[j]]){
					cout<<"not a ruler";
					f=0;
				}else{
					m[b[i]-b[j]]=1;
				}
			}
		}
		if(m.size()==b[n-1]){
			cout<<"perfect";
		}else if(f){
			cout<<"missing ";
			fora(i,1,b[n-1]){
				if(!m[i])
					cout<<i<<" ";
			}
		}
		cout<<endl;
	}
	return 0;
}
