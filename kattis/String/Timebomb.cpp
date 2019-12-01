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

int main(){
	io;
	solve();
	return 0;
}

void solve(){
	string line;
    vector<string> v(10,"");
    int n;
    map<string,int> numbers={
            {"**** ** ** ****", 0},
            {"  *  *  *  *  *", 1},
            {"***  *****  ***", 2},
            {"***  ****  ****", 3},
            {"* ** ****  *  *", 4},
            {"****  ***  ****", 5},
            {"****  **** ****", 6},
            {"***  *  *  *  *", 7},
            {"**** ***** ****", 8},
            {"**** ****  ****", 9},
    };
    fora(l,0,5){
        getline(cin,line);
        n=line.size()/4+1;
        fora(i,0,n){
            v[i]+=line.substr(i*4,3);
        }
    }
    int ans=0;
    fora(i,0,n){
        if(numbers.find(v[i])!=numbers.end()){
            ans*=10;
            ans+=numbers[v[i]];
        }else{
            cout<<"BOOM!!";
            return;
        }
    }
    if(ans%6==0){
        cout<<"BEER!!";
    }else{
        cout<<"BOOM!!";
    }
}
