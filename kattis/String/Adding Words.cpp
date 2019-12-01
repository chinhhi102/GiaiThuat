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
#include <list>
#include <stack>
#include <iterator>
#include <complex>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
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

map<int,string> nums;
map<string,int> words;

string eval(string cmd){
	string token;
	istringstream iss(cmd.substr(1));
	string ans="";
	char s='+';
	int sum=0;
	while(iss>>token){
		if(words.find(token)!=words.end()){
			if(s=='+')
				sum+=words[token];
			else if(s=='-')
				sum-=words[token];
		}else{
			ans="unknown";
			return cmd.substr(1)+" "+ans;
		}
		iss>>s;
	}
	if(nums.find(sum)!=nums.end()){
		ans=nums[sum];
	}else{
		ans="unknown";
	}
	return cmd.substr(1)+" "+ans;
}
int main(){
	io;
	string line;
	while(cin>>line){
		if(line.compare("def")==0){
			string n;
			int v;
			cin>>n>>v;
			if(words.find(n)!=words.end()){
				int va = words[n];
				words.erase(n);
				nums.erase(va);
			}
			words[n]=v;
			nums[v]=n;
		}else if(line.compare("calc")==0){
			string input;
			getline(cin,input);
			cout<<eval(input)<<endl;
		}else if(line.compare("clear")==0){
			nums.clear();
			words.clear();
		}
	}
	return 0;
}
