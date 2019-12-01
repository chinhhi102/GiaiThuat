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

#define io ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
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
#define M_PI 3.14159265358979323846
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
	freopen("D:\\Download\\codeDao\\Linhout.txt","w",stdout);
	freopen("D:\\Download\\codeDao\\Linhin.txt","r",stdin);
	map<string,char> morse;
	map<char,string> letter;
	letter[morse[".-"]	='A']=".-"	;
	letter[morse["-..."]='B']="-...";
	letter[morse["-.-."]='C']="-.-.";
	letter[morse["-.."]	='D']="-.."	;
	letter[morse["."]	='E']="."	;
	letter[morse["..-."]='F']="..-.";
	letter[morse["--."]	='G']="--."	;
	letter[morse["...."]='H']="....";
	letter[morse[".."]	='I']=".."	;
	letter[morse[".---"]='J']=".---";
	letter[morse["-.-"]	='K']="-.-"	;
	letter[morse[".-.."]='L']=".-..";
	letter[morse["--"]	='M']="--"	;
	letter[morse["-."]	='N']="-."	;
	letter[morse["---"]	='O']="---"	;
	letter[morse[".--."]='P']=".--.";
	letter[morse["--.-"]='Q']="--.-";
	letter[morse[".-."]	='R']=".-."	;
	letter[morse["..."]	='S']="..."	;
	letter[morse["-"]	='T']="-"	;
	letter[morse["..-"]	='U']="..-"	;
	letter[morse["...-"]='V']="...-";
	letter[morse[".--"]	='W']=".--"	;
	letter[morse["-..-"]='X']="-..-";
	letter[morse["-.--"]='Y']="-.--";
	letter[morse["--.."]='Z']="--..";
	letter[morse["..--"]='_']="..--";
	letter[morse["---."]='.']="---.";
	letter[morse[".-.-"]=',']=".-.-";
	letter[morse["----"]='?']="----";
	string s;
	while(cin>>s){
		vector<int> num;
		string enc="";
		fora(i,0,s.size()){
			enc+=letter[s[i]];
			num.pb(letter[s[i]].size());
		}
//		cout<<enc<<endl;
//		fora(i,0,num.size())
//			cout<<num[i];
//		cout<<endl;
		int k=0;
		fors(i,num.size(),0){
			string temp="";
			fora(j,0,num[i]){
				temp+=enc[k++];
			}
			cout<<morse[temp];
		}
		cout<<endl;
	}
	return 0;
}
