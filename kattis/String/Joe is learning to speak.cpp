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
set<string> mem[6];
int N;
int isSeparate(char c) {
	static string separate = ".,:;?!";
	return separate.find(c)!=string::npos;
}
void memorize(int n, string stmt[]) {
//	cout<<stmt[0]<<'\n';
	fora(j,1,N+1){
		for(int k=0;k+j-1<n;k++){
//			cout<<k<<" ";
			string mm="";
			fora(p,0,j){
				if(p)
					mm+="*";
				mm+=stmt[k+p];
//				cout<<mm<<" ";
			}
			mem[j].insert(mm);
		}
//		cout<<'\n';
	}
}
int check(int n,string stmt[]){
	fora(j,1,N+1){
		for(int k=0;k+j-1<n;k++){
			string mm="";
			fora(p,0,j){
				if(p)
					mm+="*";
				mm+=stmt[k+p];
			}
			if(mem[j].find(mm)==mem[j].end())
				return 1;
		}
	}
	return 0;
}
void build(){
	fora(i,1,N+1)
		mem[i].clear();
	mem[1].insert("joe");
	string stmt[128];
	char s[32];
	for(int i=0;;i++){
		int end=0,n=0;
		while(cin>>s){
			if(isSeparate(s[0]))
				break;
			if(s[0]=='*'){
				end=1;
				break;
			}
			stmt[n++]=s;
		}
		if(end)break;
		fora(j,0,n){
			fora(k,0,stmt[j].size())
				stmt[j][k]=tolower(stmt[j][k]);
		}
		memorize(n,stmt);
	}
}
void query(){
	string stmt[128], stmt2[128];
	int end=0;
	char s[32];
	for(int i=0;!end;i++){
		int n=0;
		while(cin>>s){
			if(isSeparate(s[0]))
				break;
			if(s[0]=='#') {
				end=1;
				break;
			}
			stmt[n++]=s;
		}
		fora(j,0,n){
			stmt2[j]=stmt[j];
			fora(k,0,stmt[j].size())
				stmt2[j][k]=tolower(stmt2[j][k]);
		}
		fora(j,0,n){
			if(mem[1].find(stmt2[j])==mem[1].end()){
				cout<<"What does the word "<<'"'<<stmt[j].c_str()<<'"'<<" mean?"<<endl;
				mem[1].insert(stmt2[j]);
			}
		}
		if(check(n,stmt2)){
			cout<<"What does the sentence \"";
			fora(j,0,n){
				cout<<stmt[j].c_str()<<(j==n-1?'"':' ');
			}
			cout<<" mean?"<<endl;
			memorize(n,stmt2);
		}
	}
}
void solve();
void solve2();
string tolow(const string& a){
	string ans="";
	fora(i,0,a.size())
		ans+=tolower(a[i]);
	return ans;
}

int main(){
	io;
//	solve();
	solve2();
	return 0;
}
void solve2(){
	int cases=0;
	while(cin>>N){
		cases++;
		build();
		cout<<"Learning case "<<cases<<endl;
		query();
	}
}
void solve(){
	int n;
	cin>>n;
	int k=1;
	while(n){
		cout<<"Learning case "<<k++<<endl;
		map<string,bool> m;
		m["joe"]=true;
		string s;
		string sentence="";
		vector<string> has;
		while(cin>>s&&s.compare("*")!=0){
			if(s[0]=='.'||s[0]==','||s[0]==':'||s[0]==';'||s[0]=='?'||s[0]=='!'){
				sentence.pop_back();
				fora(i,2,has.size()){
					fora(j,0,has.size()-i+1){
						string temp="";
						fora(k,j,i)
							temp+=has[k]+" ";
						temp.pop_back();
						m[temp]=true;
					}
				}
//				has.clear();
			}else{
				string p=tolow(s);
				has.pb(p);
				m[p]=true;
			}
		}
		while(cin>>s&&s.compare("#")!=0){
			if(s[0]=='.'||s[0]==','||s[0]==':'||s[0]==';'||s[0]=='?'||s[0]=='!'){
				sentence.pop_back();
				string t=tolow(sentence);
				if(m[t])
					sentence="";
				else{
					cout<<"What does the sentence "<<'"'<<sentence<<'"'<<" mean?"<<endl;
					fora(i,2,has.size()){
						fora(j,0,has.size()-i+1){
							string temp="";
							fora(k,j,i)
								temp+=has[k]+" ";
							temp.pop_back();
							m[temp]=true;
						}
					}
//					has.clear();
					sentence="";
				}
			}else{
				sentence+=s+" ";
				string p=tolow(s);
				has.pb(p);
				if(m[p])continue;
				else{
					m[p]=true;
					cout<<"What does the word "<<'"'<<s<<'"'<<" mean?"<<endl;
				}
			}
		}
		n--;
	}
}
