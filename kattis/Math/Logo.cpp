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
//#include <tuple>
#include <ctype.h>
#include <stack>
#include <iterator>
#include <complex>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <functional>
#include <time.h>
//#include <unordered_map>
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
int dist(double x,double y){
    return round(sqrt(x*x+y*y));
}
int main(){
	io;
	int cases;
    cin >> cases;
    fora(i,0,cases){
        double x = 0;
        double y = 0;
        int angle = 0;

        int commands;
        cin>>commands;

        fora(j,0,commands){
            string cmd;
            int dist;
            cin>>cmd>>dist;
            if(cmd=="lt") {
                angle += dist;
            }
            if(cmd=="rt") {
                angle -= dist;
            }
            if(cmd=="fd") {
                x += dist*sin(angle*(M_PI/ 180));
                y += dist*cos(angle*(M_PI/180));
            }
            if(cmd=="bk") {
                x -= dist*sin(angle*(M_PI/180));
                y -= dist*cos(angle*(M_PI/180));
            }
        }
        cout<<dist(x,y)<<endl;
    }
	return 0;
}
