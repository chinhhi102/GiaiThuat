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

struct point {
    double x, y;
};
double dist(point& p1,point& p2){
    return sqrt(pow(p1.x-p2.x,2)+pow(p1.y-p2.y,2));
}
int main(){
	io;
	solve();
	return 0;
}

void solve(){
	int n;
    point corners[4];
    double x,y,w,h,r;
    int q;
    bool works;
    cin>>n;
    cin.ignore();
    while(n--){
        cin>>x>>y>>w>>h>>r;
        corners[0]={x+r,y+r};
        corners[1]={x+r,y+h-r};
        corners[2]={x+w-r,y+r};
        corners[3]={x+w-r,y+h-r};
        cin>>q;
        while(q--){
        	point p;
            cin>>p.x>>p.y;
            works=false;
            if(p.x<=x+w-r&&p.x>=x+r&&p.y<=y+h&&p.y>=y){
                works=true;
            }
            if(p.x<=x+w&&p.x>=x&&p.y<=y+h-r&&p.y>=y+r){
                works=true;
            }
            for(short i=0;i<4;i++){
                if(works){
                    break;
                }
                if(dist(p,corners[i])<=r){
                    works=true;
                }
            }
            if(works){
                cout<<"inside"<<endl;
            }
            else{
                cout<<"outside"<<endl;
            }
        }
        cout<<endl;
    }
}
