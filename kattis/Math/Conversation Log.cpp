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
#include <sstream>
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
	int n;
	cin>>n;
	cin.ignore();
	map<string,map<string,int> > counts;
	map<string,int> words;
	map<string,bool> names;
	map<int,map<string,bool> > ans;
	while(n--){
		string line;
		getline(cin,line);
		istringstream iss(line.substr());
		string name;
		iss>>name;
		names[name]=true;
		string word;
		while(iss>>word){
			counts[name][word]++;
			words[word]++;
		}
	}
	for(map<string,int>::iterator it=words.begin();it!=words.end();it++){
		bool f=1;
		for(map<string,bool>::iterator itt=names.begin();itt!=names.end();itt++){
			if(!counts[itt->ff][it->ff])
				f=0;
		}
		if(f)
			ans[it->ss][it->ff]=true;
	}
	if(ans.size()){
		map<int,map<string,bool> >::iterator it=ans.end();
		while(1){
			it--;
			for(map<string,bool>::iterator itt=(it->ss).begin();itt!=(it->ss).end();itt++)
				cout<<itt->ff<<endl;
			if(it==ans.begin())
				break;
		}
	}
	else
		cout<<"ALL CLEAR";
	return 0;
}
