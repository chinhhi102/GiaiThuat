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
typedef pair<double,double> co;
typedef pair<co,co> bo;
int main(){
	io;
	int n;
	while(cin>>n&&n!=0){
		map<int,string> m;
		vector<bo > v;
		fora(i,0,n){
			double x1,y1,x2,y2;
			string type;
			cin>>x1>>y1>>x2>>y2>>type;
			m[i]=type;
			v.pb({{x1,y1},{x2,y2}});
		}
		int k;
		cin>>k;
		fora(i,0,k){
			double x,y;
			string type;
			cin>>x>>y>>type;
			cout<<type;
			int ind=0;
			for(vector<bo >::iterator it=v.begin();it!=v.end();it++){
				if(x>=(it->ff).ff&&y>=(it->ff).ss&&x<=(it->ss).ff&&y<=(it->ss).ss){
					string box_type=m[ind];
					if(box_type==type){
						cout<<" correct"<<endl;
					}
					else{
						cout<<" "<<box_type<<endl;
					}
					break;
				}
				ind++;
			}
			if(ind==v.size())
				cout<<" floor"<<endl;
			cout<<endl;
		}
	}
	return 0;
}
