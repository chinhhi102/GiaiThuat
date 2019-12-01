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
//using namespace std;

#define io ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define fora(i,a,b) for(int i=a;i<b;i++)
#define fors(i,a,b) for(int i=a-1;i>=b;i--)
#define men(a) menset(a,0,sizeof(a))
#define sc(x) scanf("%d",&x);
#define scll(x) scanf("%lld",&x);
#define c1(a) cin>>a
#define c2(a,b) cin>>a>>b
#define c3(a,b,c) cin>>a>>b>>c
#define pb push_back
#define ff first
#define ss second
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef std::pair<int,int> pi;
typedef std::pair<ll,ll> pll;
typedef std::vector<int> vi;
typedef std::vector<ll> vll;
typedef std::vector<bool> vb;
typedef std::vector<std::vector<int> > vvi;
typedef std::map<int,int> mi;
typedef std::map<long,long> mll;

void search(int x,int y);
bool check_wall_1(int x),check_wall_3(int x),check_wall_2(int y),check_wall_4(int y);
bool check(),now[100][100]={};
int n,x_point,y_point;
int count=0;
ll t=0;

int main(){
	sc(n);
	x_point=y_point=n-1;
	now[0][0]=1;
	search(0,0);
	printf("%lld %d",t,count);
	return 0;
}

bool check(){
	fora(i,0,n)fora(j,0,n)
		if(i==x_point&&j==y_point) continue;
		else if(now[i][j]==0)return 0;
	return 1;
}

void search(int x,int y){
	t++;
	if(x==x_point&&y==y_point&&check()){
		count++;
		return;
	}
	if(y==n-1&&now[x-1][y]==0&&now[x+1][y]==0&&x-1>=0&&x+1<n)   if(check_wall_1(x))return;
	if(x==n-1&&now[x][y-1]==0&&now[x][y+1]==0&&y-1>=0&&y+1<n)   if(check_wall_2(y))return;
	if(y==0&&now[x-1][y]==0&&now[x+1][y]==0&&x-1>=0&&x+1<n)	    if(check_wall_1(x))return;
	if(x==0&&now[x][y-1]==0&&now[x][y+1]==0&&y-1>=0&&y+1<n) 	 if(check_wall_2(y))return;
	
		now[x][y]=1;		
		if(now[x][y+1]==0&&y+1<n)search(x,y+1);
		if(now[x][y-1]==0&&y-1>=0)search(x,y-1);
		if(now[x+1][y]==0&&x+1<n)search(x+1,y);
		if(now[x-1][y]==0&&x-1>=0)search(x-1,y);
		if(x==0&&y==0)return;else now[x][y]=0;
}

bool check_wall_1(int x){
	bool flag=0;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(!now[i][j]){
				flag=1;
				break;
			}
		}
	}
	for(int i=x+1;i<n;i++){
		for(int j=0;j<n;j++){
			if((!now[i][j])&&flag)return 1;
		}
	}
	return 0;
}

bool check_wall_2(int y){
	bool flag=0;
	for(int i=0;i<n;i++){
		for(int j=0;j<n&&j<=y;j++){
			if(!now[i][j]){
				flag=1;
				break;
			}
		}
	}
	for(int i=0;i<n;i++){
		for(int j=y+1;j<n;j++){
			if((!now[i][j])&&flag)return 1;
		}
	}
	return 0;
}
