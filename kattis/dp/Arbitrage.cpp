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
	string name,c1,c2;
	int n;
	map<string,double> ind;
    while(cin>>n&&n){
    	double dis[n+1][n+1];
        ind.clear();
        int a,b,c,i1,i2;
        fora(i,0,n){
            cin>>name;
            ind[name] = i;
            fora(j,0,n)
				dis[i][j]=0.0;
            dis[i][i]=1.0;
        }
        int m;
        cin>>m;
        fora(i,0,m){
            cin>>c1>>c2;
            char d;
            cin>>a>>d>>b;
            i1=ind[c1];
            i2=ind[c2];
            dis[i1][i2]=max(dis[i1][i2],(double)b/(double)a);
        }
        fora(k,0,n)
            fora(i,0,n)
                fora(j,0,n)
                    dis[i][j]=max(dis[i][j],dis[i][k]*dis[k][j]);
        bool flag=true;
        fora(i,0,n)
			if(dis[i][i]>1.0)
				flag=false;
        if(flag)
			cout<<"Ok"<<endl;
        else
			cout<<"Arbitrage"<<endl;
    }

}
