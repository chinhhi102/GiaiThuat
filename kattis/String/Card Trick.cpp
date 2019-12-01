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

int main(){
	int n;
    scanf("%d", &n);
    for (int i=0;i<n;i++){
        int k;
        scanf("%d",&k);
        vector<int> v;
        for (int i=1;i<=k;i++) v.push_back(i);
        list<int> lst;
        int numberOfShifts=k;
        for (int i=k-1;i>= 0;i--){
            lst.push_front(v[i]);
            for (int i=0;i<numberOfShifts;i++){
                int tmp = lst.back();
                lst.pop_back();
                lst.push_front(tmp);
            }
            numberOfShifts--;
        }
        int ind = 0;
        for (list<int>::iterator it=lst.begin();it!=lst.end();++it){
            printf(ind==lst.size()-1?"%d\n":"%d ",*it);
            ind++;
        }
    }
	return 0;
}
