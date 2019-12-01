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

int main(){
	string cate[4]={"single","double","triple"};
	int scores[]={
    	1,2,3,
    	2,4,6,
    	3,6,9,
   		4,8,12,
    	5,10,15,
    	6,12,18,
    	7,14,21,
    	8,16,24,
    	9,18,27,
    	10,20,30,
    	11,22,33,
    	12,24,36,
    	13,26,39,
    	14,28,42,
    	15,30,45,
    	16,32,48,
    	17,34,51,
    	18,36,54,
	    19,38,57,
	    20,40,60};
	int score;
	sc(score);
	fora(i,0,60){
		if(scores[i]==score){
			cout<<cate[i%3]<<" "<<i/3+1<<endl;
			return 0;
		}
		fora(j,0,60){
			if(scores[i]+scores[j]==score){
				cout<<cate[i%3]<<" "<<i/3+1<<endl;
				cout<<cate[j%3]<<" "<<j/3+1<<endl;
				return 0;
			}
			fora(k,0,60){
				if(scores[i]+scores[j]+scores[k]==score){
					cout<<cate[i%3]<<" "<<i/3+1<<endl;
					cout<<cate[j%3]<<" "<<j/3+1<<endl;
					cout<<cate[k%3]<<" "<<k/3+1<<endl;
					return 0;
				}
			}
		}
	}
	printf("impossible\n");
	return 0;
}
