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
vector<vector<int>> getpiece(int piece){
	vector<vector<int>> res;
	if(piece==1){
		res.pb({0});
		res.pb({0,0,0,0});
	}
	if(piece==2){
		res.pb({0,0});
	}
	if(piece==3){
		res.pb({0,0,1});
		res.pb({1,0});
	}
	if(piece==4){
		res.pb({1,0,0});
		res.pb({0,1});
	}
	if(piece==5){
		res.pb({1,0,1});
		res.pb({0,0,0});
		res.pb({1,0});
		res.pb({0,1});
	}
	if(piece==6){
		res.pb({2,0});
		res.pb({0,1,1});
		res.pb({0,0});
		res.pb({0,0,0});
	}
	if(piece==7){
		res.pb({0,2});
		res.pb({1,1,0});
		res.pb({0,0});
		res.pb({0,0,0});
	}
	return res;
}
int gettotal(vector<int>& board,vector<int>& piece){
	int s=0;
	fora(i,0,board.size()-piece.size()+1){
		bool work=true;
		int diff=board[i]-piece[0];
		fora(j,1,piece.size()){
			if(diff!=board[i+j]-piece[j])
				work=false;
		}
		if(work)
			s++;
	}
	return s;
}
int main(){
	io;
	solve();
	return 0;
}

void solve(){
	int col,piece;
	cin>>col>>piece;
	vector<int>board(col);
	fora(i,0,col)
		cin>>board[i];
	vector<vector<int>> pie=getpiece(piece);
	int total=0;
	for(auto i:pie)
		total+=gettotal(board,i);
    cout<<total<<endl;
}
