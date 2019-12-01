#ifndef competitive_programming_H
#define competitive_programming_H
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
#define fix(x) cout<<fixed<<setprecision(x)
#define UNIQUE(c) (c).resize(unique(all(c))-(c).begin())
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
#endif
void solve();

int main(){
	io;
	solve();
	return 0;
}

void solve(){
	map<int,vector<string>> m;
	m[0]={	"+---+",
			"|   |",
			"|   |",
			"+   +",
			"|   |",
			"|   |",
			"+---+"};
	m[1]={	"    +",
			"    |",
			"    |",
			"    +",
			"    |",
			"    |",
			"    +"};
	m[2]={	"+---+",
			"    |",
			"    |",
			"+---+",
			"|    ",
			"|    ",
			"+---+"};
	m[3]={	"+---+",
			"    |",
			"    |",
			"+---+",
			"    |",
			"    |",
			"+---+"};
	m[4]={	"+   +",
			"|   |",
			"|   |",
			"+---+",
			"    |",
			"    |",
			"    +"};
	m[5]={	"+---+",
			"|    ",
			"|    ",
			"+---+",
			"    |",
			"    |",
			"+---+"};
	m[6]={	"+---+",
			"|    ",
			"|    ",
			"+---+",
			"|   |",
			"|   |",
			"+---+"};
	m[7]={	"+---+",
			"    |",
			"    |",
			"    +",
			"    |",
			"    |",
			"    +"};
	m[8]={	"+---+",
			"|   |",
			"|   |",
			"+---+",
			"|   |",
			"|   |",
			"+---+"};
	m[9]={	"+---+",
			"|   |",
			"|   |",
			"+---+",
			"    |",
			"    |",
			"+---+"};
	string line;
	while(cin>>line&&line[0]!='e'){
		line.erase(2,1);
		vector<string> res(7,"");
		fora(i,0,7){
			fora(j,0,4){
				res[i]+=m[line[j]-'0'][i];
			if(j<3)
				res[i]+="  ";
			if(j==1)
				if(i==2||i==4)
					res[i]+="o  ";
				else
					res[i]+="   ";
			}
		}
		fora(i,0,res.size()){
			cout<<res[i]<<endl;
		}
		cout<<endl<<endl;
	}
	cout<<"end"<<endl;
}
