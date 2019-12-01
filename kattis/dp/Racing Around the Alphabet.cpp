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
#define for(i,a,b) for(int i=a;i<=b;i++)
#define fors(i,a,b) for(int i=a;i>=b;i--)
#define men(a) menset(a,0,sizeof(a))
#define sc(x) scanf("%d",&x);
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

#define STEP_LENGTH 6.731984257692413
int to_int(char x){return x==' '?26:x=='\''?27:x-'A';}
int shortest_route(char a, char b){
    if (a == b) return 0;
    int _a = to_int(a), _b = to_int(b);
    if (_b < _a){
        _a ^= _b;
        _b ^= _a;
        _a ^= _b;
    }
    return min(_b - _a, (28 - _b) + _a);
}

int run(char* str, int len){
    len--;
    int counter = 0;
    for(i,0,len-1) counter += shortest_route(str[i], str[i+1]);
    return counter;
}

int main(){
	io;
	int n;sc(n);
	char text[n][121];fflush(stdin);
	for(i,0,n-1) gets(text[i]);
	for(i,0,n-1) printf("%.10f\n",run(text[i],strlen(text[i]))*STEP_LENGTH/15+strlen(text[i]));
	return 0;
}
