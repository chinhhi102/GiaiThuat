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

int main(){
    int f, r;
    while (scanf("%d%d",&f,&r)==2){
        vi trc;
        int a;
        fora(i,0,f){
            sc(a);
            trc.pb(a);
        }
        vi sau;
        fora(i,0,r){
            sc(a);
            sau.pb(a);
        }

        vector<float> ti_le_2_banh_rang;
        for (vi::iterator it1=trc.begin();it1!=trc.end();it1++){
            for (vi::iterator it2=sau.begin();it2!=sau.end();it2++){
                ti_le_2_banh_rang.pb(*it2 / float(*it1));
            }
        }

        sort(ti_le_2_banh_rang.begin(),ti_le_2_banh_rang.end());
		float res(0);
        vector<float> muc_phat_tan;
        fora(i,1,ti_le_2_banh_rang.size()){
			muc_phat_tan.pb(ti_le_2_banh_rang[i] / ti_le_2_banh_rang[i-1]);
  	    	res=max(res,muc_phat_tan[i-1]);
		}
        printf("%.2f\n",res);
  }
	return 0;
}
