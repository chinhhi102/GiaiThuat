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

void solve();
struct arr{
	int a[10];
	int dem=0;
}fo;
bool cp(arr x,arr y){
	fora(i,0,10){
		if(x.a[i]!=y.a[i])return 0;
	}
	return 1;
}
set<arr> s;
//map<arr,bool> m;
//bool found(queue<arr>& q){
//	queue<arr> nq;
//	dem++;
//	while(!q.empty()){
//		arr cur[2];
//		fora(i,0,2)
//			cur[i]=q.front();
//		q.pop();
//		fora(i,0,2){
//			int x=cur[i].a[1+i];
//			cur[i].a[1+i]=cur[i].a[0+i];
//			cur[i].a[0+i]=cur[i].a[3+i];
//			cur[i].a[3+i]=cur[i].a[7+i];
//			cur[i].a[7+i]=cur[i].a[8+i];
//			cur[i].a[8+i]=cur[i].a[5+i];
//			cur[i].a[5+i]=x;
//			if(cp(cur[i],fo))return false;
////			nq.push(cur[i]);
//			if(s.count(cur[i])==0){
//				s.insert(cur[i]);
//				nq.push(cur[i]);
//			}
////			cout<<nq.size()<<endl;
//		}
//	}
//	q=nq;
//	return true;
//}
int main(){
	io;
	solve();
	return 0;
}

void solve(){
	arr data;
//	vector<int> data(10);
	fo.a[0]=1;
	fo.a[1]=2;
	fo.a[2]=3;
	fo.a[3]=8;
	fo.a[4]=0;
	fo.a[5]=0;
	fo.a[6]=4;
	fo.a[7]=7;
	fo.a[8]=6;
	fo.a[9]=5;
	fora(i,0,10)
		cin>>data.a[i];
	queue<arr> q;
	q.push(data);
	while(1){
		arr cur[2];
		fora(i,0,2)cur[i]=q.front();
		q.pop();
		fora(i,0,2){
			int x=cur[i].a[1+i];
			cur[i].a[1+i]=cur[i].a[0+i];
			cur[i].a[0+i]=cur[i].a[3+i];
			cur[i].a[3+i]=cur[i].a[7+i];
			cur[i].a[7+i]=cur[i].a[8+i];
			cur[i].a[8+i]=cur[i].a[5+i];
			cur[i].a[5+i]=x;
			cur[i].dem++;
//			cout<<cur[i].dem<<endl;
			if(cp(cur[i],fo)){
				cout<<cur[i].dem<<endl;
				return;
			}
			q.push(cur[i]);
		}
	}
}
