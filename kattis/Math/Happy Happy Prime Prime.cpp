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
const int MAXSANG = 10001;
void solve();
map<int ,int >m;
bool kt(int num){
	int d=num%10,temp=num;
	while(temp/=10){
		d+=temp%10;
	}
	if(d==1)
		return false;
	while(num!=1){
		if(m[num]){
			return false;
		}else{
			m[num]=1;
			int temp=0;
			int j=num;
			for(;j>0;j=j/10){
				temp=temp+pow(j%10,2);
			}
			num=temp;
		}
	}
	return true;
}
int snt[MAXSANG+1];
void sangnt(){
    long i,j;
    for(i=1; i<=MAXSANG; i++)
        snt[i]=1;
    snt[1]=0;
    i=2;
    while (i<=sqrt(MAXSANG))
    {
        while (snt[i]==0)
            i++;
        for (j=2; j<=MAXSANG/i; j++)
            snt[i*j]=0;
        i++;
    }
}
int main(){
	io;
	solve();
	return 0;
}

void solve(){
	int n;
	sangnt();
	cin>>n;
	for(int i=0;i<n;i++){
		int ind,num;
		cin>>ind>>num;
		cout<<ind<<"\t"<<num<<"\t"<<((kt(num)&&snt[num])?"YES":"NO")<<endl;
		m.clear();
	}
}
