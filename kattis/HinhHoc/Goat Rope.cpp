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
#define EPS 0.000000001
#define fix(x) cout<<fixed<<setprecision(x)
#define UNIQUE(c) (c).resize(unique(all(c))-(c).begin())
#define debug freopen("D:\\baiTapLapTrinh\\UVa\\out.txt","w",stdout);
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

struct point{ double x,y;
  point(){ x = y = 0.0;  }
  point( int _x,int _y) : x(_x), y(_y) {}
};

struct line{ double a,b,c; };

struct vec{ double x,y;
  vec(double _x, double _y) : x(_x), y(_y) {} };

vec toVec(point a,point b) {
	return vec(b.x - a.x,b.y - a.y);
}

vec scale(vec v,double s){
	return vec(v.x * s,v.y * s);
}

point translate(point p,vec v){
	return point(p.x + v.x, p.y + v.y);
}

void pointsToLine(point p1, point p2, line &l){
  if(fabs(p1.x - p2.x) < EPS) {
  	l.a = 1.0; l.b = 0.0; l.c = -p1.x;
  }else{
  	l.a = -(double)(p1.y - p2.y) / (p1.x - p2.x);
  	l.b = 1.0;
  	l.c = -(double)(l.a * p1.x) - p1.y;
  }
}

double hypot(double x,double y){
  return sqrtl(x*x + y*y);
}

double dist(point p1,point p2) {
//	fix(4)<<p1.x<<' '<<p1.y<<' '<<p2.x<<' '<<p2.y<<endl;
  return hypot(p1.x - p2.x,p1.y - p2.y);
}

double dot(vec a,vec b){ return (a.x * b.x + a.y * b.y); }

double norm_sq(vec v) { return v.x * v.x + v.y * v.y; }

double distToLine(point p,point a,point b){
  vec ap = toVec(a,p),ab = toVec(a,b);
  double u = dot(ap,ab) / norm_sq(ab);
  point c;
  c=translate(a,scale(ab,u));
  return dist(p,c);
}

double distToLineSegment(point p,point a,point b){
  vec ap = toVec(a,p), ab = toVec(a,b);
  double u = dot(ap,ab) / norm_sq(ab);
  if(u < 0.0)
  	return dist(p,a);
  if(u > 1.0)
  	return dist(p,b);
  return distToLine(p,a,b);
}

void getpoint(point A,point &B,point C,point &D){
    B.x=C.x;B.y=A.y;
    D.x=A.x;D.y=C.y;
}

int main(){
	io;
	solve();
	return 0;
}

void solve(){
	point O,A,B,C,D;
	cin>>O.x>>O.y>>A.x>>A.y>>C.x>>C.y;
	getpoint(A,B,C,D);
	double res;
	res=min(min(distToLineSegment(O,A,B),distToLineSegment(O,B,C)),min(distToLineSegment(O,C,D),distToLineSegment(O,D,A)));
	fix(5)<<res;
}
