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

int main(){
	io;
	int n;
	char line[15]={'G','F','E','D','C','B','A','g','f','e','d','c','b','a'};
	map<char,string> musical;
	musical['G']="";
	musical['F']="";
	musical['E']="";
	musical['D']="";
	musical['C']="";
	musical['B']="";
	musical['A']="";
	musical['g']="";
	musical['f']="";
	musical['e']="";
	musical['d']="";
	musical['c']="";
	musical['b']="";
	musical['a']="";
	cin>>n;
	int id=0;
	fora(i,0,n){
		string 	song;
		cin>>song;
		if(song.size()==2){
//			int len=musical[song[0]].size();
			if(song[0]=='F'||song[0]=='D'||song[0]=='B'||song[0]=='g'||song[0]=='e'||song[0]=='a'){
				musical[song[0]].resize(id,'-');
				int t=song[1]-'0';
				fora(j,0,t){
					musical[song[0]]+="*";
					id++;
				}
				id++;
			}else{
				musical[song[0]].resize(id,' ');
				int t=song[1]-'0';
				fora(j,0,t){
					musical[song[0]]+="*";
					id++;
				}
				id++;
			}
		}else{
			if(song[0]=='F'||song[0]=='D'||song[0]=='B'||song[0]=='g'||song[0]=='e'||song[0]=='a'){
				musical[song[0]].resize(id,'-');
				musical[song[0]]+="*";
				id+=2;
			}else{
				musical[song[0]].resize(id,' ');
				musical[song[0]]+="*";
				id+=2;
			}
		}
	}
	fora(i,0,14){
		if(line[i]=='F'||line[i]=='D'||line[i]=='B'||line[i]=='g'||line[i]=='e'||line[i]=='a')
			musical[line[i]].resize(id-1,'-');
		else
			musical[line[i]].resize(id-1,' ');
		cout<<line[i]<<": "<<musical[line[i]]<<endl;
	}
	return 0;
}
