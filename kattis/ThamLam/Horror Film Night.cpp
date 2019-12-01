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
	int n,m;
	vector<bool> v1, v2;
    v1.resize(1000000, false);
    v2.resize(1000000, false);
    int s;
    cin >> s;
    for(int i = 0; i < s; i++) {
        int temp;
        cin >> temp;
        v1[temp] = true;
    }
    cin >> s;
    for(int i = 0; i < s; i++) {
        int temp;
        cin >> temp;
        v2[temp] = true;
    }
    bool h1 = true, h2 = true;
    int total = 0;
    for(int i = 0; i < 1000000; i++) {
        if(v1[i] && v2[i]) {
            h1 = true;
            h2 = true;
            total++;
        }
        else if(v1[i] && h2) {
            h1 = true;
            h2 = false;
            total++;
        }
        else if(v2[i] && h1) {
            h1 = false;
            h2 = true;
            total++;
        }
    }
    cout << total << endl;
	return 0;
}
