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
#define M_PI 3.14159265358979323846
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
	int n;
	cin>>n;
	cin.ignore();
	string s;
	cin>>s;
	int sum=0,ans=0,i=0;
	while(!s.empty()){
		if(sum>0&&s[i+1]=='W'){
			sum--;
			s.erase(s.begin()+i+1);
		}else if(sum<0&&s[i+1]=='M'){
			sum++;
			s.erase(s.begin()+i+1);
		}else if(s[i]=='M'){
			sum++;
			s.erase(s.begin()+i);
		}
		else{ 
			sum--;
			s.erase(s.begin()+i);
		}
		if(abs(sum)>n)break;
		else ans++;
	}
	cout<<ans;
	return 0;
}
