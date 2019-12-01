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
	int n;
	cin>>n;
	string M[n];
	fora(i,0,n)
		cin>>M[i];
	int f=0;
	fora(i,0,n){
		if(f)break;
		fora(j,0,n){
			if(f)break;
			if(M[i][j]=='.')continue;
			if(M[i][j]=='x'){
				int d1=0,d2=0,d3=0,d4=0;
				fora(k,0,5){
					if((i+k)<n&&M[i+k][j]=='x')
						d1++;
					if((i+k)<n&&(j+k)<n&&M[i+k][j+k]=='x')
						d2++;
					if((j+k)<n&&M[i][j+k]=='x')
						d3++;
					if((i-k)>=0&&(j+k)<n&&M[i-k][j+k]=='x')
						d4++;
				}
				if(d1==5||d2==5||d3==5||d4==5)
					f=1;
			}else{
				int d1=0,d2=0,d3=0,d4=0;
				fora(k,0,5){
					if((i+k)<n&&M[i+k][j]=='o')
						d1++;
					if((i+k)<n&&(j+k)<n&&M[i+k][j+k]=='o')
						d2++;
					if((j+k)<n&&M[i][j+k]=='o')
						d3++;
					if((i-k)>=0&&(j+k)<n&&M[i-k][j+k]=='o')
						d4++;
				}
				if(d1==5||d2==5||d3==5||d4==5)
					f=-1;
			}
		}
	}
	if(!f)
		cout<<"Not yet";
	else
		cout<<(f+1?"Ti wins":"Teo wins");
}
