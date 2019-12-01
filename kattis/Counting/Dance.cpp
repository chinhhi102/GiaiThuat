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
int n;
bool next(vector<int>& v){
	fors(i,n,0){
		fors(j,i,0){
			if(v[i]>v[j]){
				swap(v[i],v[j]);
				sort(v.begin()+j+1,v.end());
				return false;
			}
		}
	}
	return true;
}
int findbest(vector<vi >& dis,vi& v){
    int total=0;
    fora(i,1,v.size()){
        total+=dis[v[i]][v[i-1]];
    }
    return total;
}
int dist(string a,string b){
	vector<bool> sa(26),sb(26);
	int ans=0;
	fora(i,0,a.size())
		sa[a[i]-'A']=1;
	fora(i,0,b.size())
		sb[b[i]-'A']=1;
	fora(i,0,26){
		if(sa[i]&&sb[i])
			ans++;
	}
	return ans;
}
int main(){
	io;
	cin>>n;
	vector<string> str(n);
	fora(i,0,n)
		cin>>str[i];
	vector<int> v(n);
	fora(i,0,n)
		v[i]=i;
	bool f=false;
	int res=1001;
	vector<vi > dis(n,vi(n));
	fora(i,0,n)
		fora(j,i+1,n){
			dis[i][j]=dist(str[i],str[j]);
			dis[j][i]=dis[i][j];
		}
	do{
		res=min(res,findbest(dis,v));
	}while(next_permutation(v.begin(),v.end()));
	cout<<res;
	return 0;
}
