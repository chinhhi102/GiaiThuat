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
	string dashes(40,'-');
    int T;
    cin>>T;
    fora(test_case,0,T){
        int r,p,d;
        cin>>r>>p>>d;
        vector<string> names(r);
        vector<double> weights(r),pcts(r);
        int main_ingred;
        fora(i,0,r){
            cin>>names[i]>>weights[i]>>pcts[i];
            if(pcts[i]==100.0) {
                main_ingred=i;
            }
        }
        double factor=static_cast<double>(d)/p;
        double scaled_main=weights[main_ingred]*factor;
        cout<<"Recipe # "<<test_case+1<<endl;
        fora(i,0,r){
            double ans=scaled_main*pcts[i]/100.0;
            cout<<setprecision(10)<<fixed<<names[i]<<' '<<ans<<endl;
            // cout << fixed << setprecision(10) << names[i] << ' ' << ans << '\n';
        }
        cout<<dashes<<endl;
    }
}
