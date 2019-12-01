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

int T,A;
ll N;
ll dp[33][33];
int main(){
	io;
    cin>>T;
    fora(i,0,33){
        dp[0][i]=1;
        dp[i][0]=1;
    }
    fora(i,1,33)
        fora(j,1,33)
            dp[i][j]=dp[i-1][j-1]+dp[i-1][j];
    while (T--){
        cin>>N>>A;
        int low = 0, high = 32;
        while (low<=high){
            int mid = (high+low)>>1;
            if (dp[mid][A] > N)
                high = mid-1;
            else
                low = mid+1;
//            cout<<low<<" "<<mid<<" "<<high<<endl;
		}
        if (low>32)
            cout<<"Impossible"<<endl;
        else
            cout<<low<<endl;
    }
}
