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
int dx[]={1,0,-1,0};
int dy[]={0,1,0,-1};
map<char,int> dc;
int main(){
	io;
	dc['r']=0;
	dc['u']=1;
	dc['l']=2;
	dc['d']=3;
	int Max_width,Max_lenght;
	while(cin>>Max_width>>Max_lenght){
		if(Max_width==0&&Max_lenght==0)break;
		int x_robot=0,y_robot=0,x_act=0,y_act=0;
		int n;
		cin>>n;
		fora(i,0,n){
			int y;
			char x;
			cin>>x>>y;
			x_robot+=dx[dc[x]]*y;
			y_robot+=dy[dc[x]]*y;
			if(x_act+dx[dc[x]]*y>=0&&y_act+dy[dc[x]]*y>=0){
				x_act=(x_act+dx[dc[x]]*y<Max_width)?x_act+dx[dc[x]]*y:Max_width-1;
				y_act=(y_act+dy[dc[x]]*y<Max_lenght)?y_act+dy[dc[x]]*y:Max_lenght-1;
			}
			else{//toa do <0
				x_act=(x_act+dx[dc[x]]*y>=0)?x_act:0;
				y_act=(y_act+dy[dc[x]]*y>=0)?y_act:0;
			}
		}
		cout<<"Robot thinks "<<x_robot<<" "<<y_robot<<endl;
		cout<<"Actually at "<<x_act<<" "<<y_act<<endl;
	}
	return 0;
}
