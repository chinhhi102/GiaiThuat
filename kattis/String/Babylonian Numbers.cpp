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

void solve();
int to_num(string a){
	int num=0;
	if(a.size()==0)
		return 0;
	fors(i,a.size(),0){
		num=num*10+(a[i]-'0');
	}
//	cout<<num<<endl;
	return num;
}
int main(){
	io;
	solve();
	return 0;
}

void solve(){
	int n;
	cin>>n;
	while(n--){
		vector<ll> v;
        string s;
        cin>>s;
        string actual;
        for(auto c:s){
            if(c==','){
                actual.push_back(',');
                actual.push_back('0');
            }
            else{
                actual.push_back(c);
            }
        }
        vector<string> split;
        split.push_back("");
        for(auto c:actual){
            if(c==','){
                split.push_back("");
            }
            else{
                split[split.size()-1].push_back(c);
            }
        }
        ll total=0;
        fora(i,0,split.size()){
            string temp=split[split.size()-i-1];
            total+=pow(60,i)*stoi(temp);
        }
        cout<<total<<endl;
	}
}
