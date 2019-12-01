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
void process(vector<int>& v, vector<int> costs, int order) {
    vector<int> ans;
    if(v[order]==-2){
        cout<<"Impossible"<<endl;
        return;
    }
    if(v[order]==-1){
        cout<<"Ambiguous"<<endl;
        return;
    }
    while(order>0){
        ans.push_back(v[order]+1);
        order-=costs[v[order]];
    }
    if(order<0){
        cout<<"Ambiguous"<<endl;
        return;
    }
    sort(ans.begin(),ans.end());
    for(auto i:ans){
        cout<<i<<" ";
    }
    cout<<endl;
}
int main(){
	io;
	solve();
	return 0;
}

void solve(){
	vector<int> v(32000,-2);
    v[0]=0;
    int n;
    cin>>n;
    vector<int> costs(n);
    for(auto& i:costs){
        cin>>i;
    }
    fora(i,0,n){
        int cost=costs[i];
        fora(j,0,30001){
            if(v[j]>=0) {
                if(v[j+cost]==-2) {
                    v[j+cost]=i;
                }else{
                    v[j+cost]=-1;
                }
            }
            if(v[j]==-1){
                v[j+cost]=-1;
            }
        }
    }
    int q;
    cin>>q;
    fora(i,0,q){
        int order;
        cin>>order;
        process(v,costs,order);
    }
}
