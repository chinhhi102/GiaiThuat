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

string low(string inp){
    string res;
    locale loc;
    for(string::size_type i=0;i<inp.size();i++)
		res+=tolower(inp[i],loc);
    return res;
}

int main(){
	string s;
    int i=0;
    vector<string> v;
    vector<string>::iterator iter=v.begin();
    while(cin>>s){
        if(!i){
			v.pb(low(s));
			cout<<s;
		}else{
            iter=find(v.begin(),v.end(),low(s));
            if(iter!=v.end())
				cout<<" .";
			else{
				cout<<" "<<s;
				v.pb(low(s));
			}
        }
        i++;
    }
	return 0;
}
