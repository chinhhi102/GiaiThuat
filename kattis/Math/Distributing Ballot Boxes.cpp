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

class mycomparison{
    public:
    bool operator() (const pair<ll,ll>& lhs, const pair<ll,ll>& rhs) const {
        if(ceil(lhs.first / double(lhs.second)) == ceil(rhs.first / double(rhs.second))) {
            return lhs.second > rhs.second;
        }
        return ceil(lhs.first / double(lhs.second)) < ceil(rhs.first / double(rhs.second));
    }
};

void solve();

int main(){
	io;
	solve();
	return 0;
}

void solve(){
	ll n,b;
    while(cin>>n&&cin>>b&&!(n==-1||b==-1)){
        priority_queue<pair<ll, ll>,vector<pair<ll,ll>>,mycomparison> q;
        for(ll i=0;i<n;i++) {
            ll temp;
            cin>>temp;
            q.push({temp,1});
        }
        b-=n;
        for(ll i=0;i<b;i++) {
            pair<int,int> p=q.top();
            q.pop();
            p.second++;
            q.push(p);
        }
        cout<<ceil(q.top().first/double(q.top().second))<<endl;
    }
}
