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
# define NR 100005
int i,n,poz,l;
double rez[100], sol;
char s[NR];

double eval(int &poz);
double termen(int &poz);
double factor(int &poz);

double eval(int &poz) {
    ++poz;
    double sol=termen(poz);
    while (s[poz]=='-' && poz<=l) {
        ++poz;
        sol+=termen(poz);
    }
    ++poz;
    return sol;
}
double termen (int &poz) {
    double sol=factor(poz);
    if (s[poz]=='|') {
        sol=((double)(1))/sol;
        while (s[poz]=='|' && poz<=l) {
            ++poz;
            sol+=(((double)(1))/factor(poz));
        }
        return ((double)(1))/sol;
    }else return sol;
}
double factor (int &poz) {
    double sol;
    if (s[poz]=='R') {
        ++poz;
        sol=rez[s[poz]-'0'];
        ++poz;
    }else sol=eval(poz);
    return sol;
}
int main(){
	io;
	cin>>n;
    fora(i,1,n+1)
        cin>>rez[i];
    cin.get();
    cin.getline(s+1,NR);
	l=strlen(s+1);
    poz=0;
    fix(6);
    cout<<eval(poz);
	return 0;
}
