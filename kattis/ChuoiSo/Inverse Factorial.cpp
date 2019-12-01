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
#define sc(x) scanf("%d",&x);
#define scll(x) scanf("%lld",&x);
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

int pre_defined(int n){
    return n == 1 ? 1 : n == 2 ? 2 : n == 6 ? 3 : n == 24 ? 4 : n == 120 ? 5 : 6;
}

int main(){
	char n[1000001];
	gets(n);
	size_t digits = strlen(n);
	if(digits<4)
		printf("%d\n",pre_defined(atoi(n)));
	else{
		int number = 6;
        double log_sum = log10(720);
        while (1){
            log_sum += log10(++number);
            if (log_sum > digits){
                printf("%d\n", number - 1);
                break;
            }
        }
    }
	return 0;
}
