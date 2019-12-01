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
	map<int,string> names;
	names[100]="onehundred";
	names[200]="twohundred";
	names[300]="threehundred";
	names[400]="fourhundred";
	names[500]="fivehundred";
	names[600]="sixhundred";
	names[700]="sevenhundred";
	names[800]="eighthundred";
	names[900]="ninehundred";
	
	names[20]="twenty";
	names[30]="thirty";
	names[40]="forty";
	names[50]="fifty";
	names[60]="sixty";
	names[70]="seventy";
	names[80]="eighty";
	names[90]="ninety";	
	
	names[11]="eleven";
	names[12]="twelve";
	names[13]="thirteen";
	names[14]="fourteen";
	names[15]="fifteen";
	names[16]="sixteen";
	names[17]="seventeen";
	names[18]="eighteen";
	names[19]="nineteen";
	
	names[1]="one";
	names[2]="two";
	names[3]="three";
	names[4]="four";
	names[5]="five";
	names[6]="six";
	names[7]="seven";
	names[8]="eight";
	names[9]="nine";
	names[10]="ten";
	names[0]="";
	map<int, int> m;
    fora(i,1,1000){
        string ans="";
        int h=i/100;
        h*=100;
        int t=i-h;
        if(names.find(h)!=names.end()){
            ans+=names[h];
        }
        if(names.find(t)!=names.end()){
            ans+=names[t];
        }else{
            ans+=names[10*(t/10)];
            ans+=names[t%10];
        }
        names[i]=ans;
        int pos=i-ans.size();
		if(m.find(pos)==m.end()){
            m[pos]=i;
        }
    }
	int n;
	cin>>n;
	string ans="";
	bool f=true;
	int d=0;
	fora(i,0,n){
		string s;
		cin>>s;
		ans+=s+" ";
	}
	int length=ans.size()-n-1;
	auto pos=ans.find('$');
	ans.replace(pos,1,names[m[length]]);
	ans.pop_back();
	cout<<ans<<endl;
}
