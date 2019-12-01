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
	map<char,bool> letter;
	fora(i,0,26){
		letter[i+'a']=1;
		letter[i+'A']=1;
	}
	int n;
	cin>>n;
	string line;
	cin.ignore();
	fora(i,0,n){
		getline(cin,line);
		int d=0;
		bool f=1;
		fora(j,0,line.size())
			if(letter[line[j]]){
				letter[line[j]]=0;
			}
		fora(j,0,26)
			if(letter[j+'a']&&letter[j+'A']){
				if(f){
					cout<<"missing "<<char(j+'a');
					f=0;
				}else
					cout<<char(j+'a');
			}else
				letter[j+'a']=letter[j+'A']=1;
		if(f)
			cout<<"pangram";
		cout<<endl;
	}
	return 0;
}