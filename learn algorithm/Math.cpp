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

int main(){
	io;
	solve();
	return 0;
}

struct point{ double x,y;	
  point(){ x=y=0.0;  }			
  point(double _x,double _y) : x(_x), y(_y) {} // EPS = 1e-9
  bool operator < (point other) const {  // override less than operator
    if (fabs(x - other.x) > EPS)				// useful for sorting
      return x < other.x;			// first criteria , by x - coordinate
    return y < other.y;				// second criteria, by y - coordinate
  }
  bool operator == (point other) const {  // test if two points are equal
    return (fabs(x- other.x) < EPS && (fabs(y - other.y) < EPS)); 
  }
};

double dist(point p1, point p2) { // Eucludean distance
  return hypot(p1.x - p2.x, p1.y - p2.y); // hypot(dx, dy) returns sqrt (dx * dx + dy * dy)
}

point rotate(point p, double theta) {
  double rad = DEG_to_RAD(theta); // multiply theta with PI / 180.0
  return point( p.x * cos(rad) - p.y * sin(rad),
  				p.x * sin(rad) + p.y * cos(rad));	
}

struct line { double a,b,c };

// the answer is stored in the third parameter (pass by reference )
void pointsToLine(point p1,point p2, line &l) {
  if(fabs(p1.x - p2.x) < EPS){		// vertical line is fine
    l.a = 1.0;    l.b = 0.0;    l.c = -p1.x;  //default values
  } else {
    l.a = -(double)(p1.y - p2.y) / (p1.x - p2.x);
    l.b = 1.0;		//IMPORTANT: we fix the value of b to 1.0
	l.c = -(double)(l.a * p1.x) - p1.y;
  }
}

bool areParallel(line l1, line l2){		// check coefficients a & b
  return (fabs(l1.a - l2.a) < EPS) && (fabs(l1.b - l2.b) < EPS);
}

bool areSame(line l1,line l2){		//also check coeficient c
  return areParallel(l1,l2) && (fabs(l1.c - l2.c) < EPS);
}

//return true (+ intersection point) if two lines are intersect
bool areIntersect(line l1, line l2, point &p) {
  if(areParallel(l1,l2)) return false;	//no intersection
  // solve system of 2 linear algebraic equtions with 2 unknowns
  p.x = (l2.b * l1.c - l1.b * l2.c) / (l2.a * l1.b - l1.a * l2.b)
  // special case: test for vertical line to avoid division by zero
  if(fabs(l1.b) > EPS)  p.y = -(l1.a * p.x + l1.c);
  else				 	p.y = -(l2.a * p.x + l2.c);
  return true;
}

struct vec { double x,y;
  vec(double _x,double _y) : x(_x), y(_y) {}
};

vec toVec(point a,point b) {	//convert 2 points to vector a->b
  return vec(b.x - a.x, b.y - a.y);
}

vec scale(vec v, double s) {	// nonnegative s = [<1...1...>1]
  return vec(v.x * s, v.y * s);			// shorter.same.longer
}

point translate(point p, vec v) {	// translate p according to v
  return point(p.x + v.x , p.y + v.y);
}

double dot(vec a,vec b) { return (a.x * b.x + a.y * b.y);}

double norm_sq(vec v){ return (v.x * v.x + v.y * v.y);}

// return the distance from p to the line defined by
// two points a and b (a and b must be different)
// the closest point is stored in the 4th parameter (byref)
double distToLine(point p,point a,point b,point &c) {
  // formula: c = a + u * ab
  vec ap = toVec(a,p), ab = toVec(a,b);
  double u = dot(ap,ab) / norm_sq(ab);
  c = translate(a, scale(ab, u));		// translate a to c
  return dist(p, c);		// Euclidean distance between p and c
}

// return the distance from p to the line segment ab defined by
// two points a and b (still OK if a == b)
// the closest point is stored in the 4th parameter (byref)
double distToLineSegment(point p,point a,point b,point &c) {
  vec ap = toVec(a,p), ab = toVec(a,b);
  double u = dot(ap,ab) / norm_sq(ab);
  if(u<0.0){
    c = point(a.x,a.y);		// closer to a
    return dist(p,a);
  }
  if(u>1.0){
    c = point(b.x,b.y);		// closer to b
    return dist(p,b);
  }
  return distToLine(p,a,b,c);	// middle a and b
}

//Since oa.ob = |oa| x |ob| x cos(theta), we have theta = acos(oa.ob/|oa|x|ob|)
double angle(point a,point o,point b) { // return angle aob in rad
  vec oa = toVec(o,a),ob = toVec(o,b);  //norm_sq is |o->b|
  return acos(dot(oa,ob) / sqrt(norm_sq(oa) * norm_sq(ob)));
}

double cross(vec a, vec b) { return (a.x * b.y - a.y * b.x);}

// note: CCW is Counter Clockwise, to accept collinear points,
// we have to change the '> 0'
// return true if point r is on the left side of line pq
bool ccw(point p,point q,point r) {
	return cross(toVec(p,q),toVec(p,r)) > 0;
}

// return true if point r is on the same line as the line pq
bool collinear(point p,point q,point r) {
	return fabs(cross(toVec(p,q),toVec(p,r))) < EPS;
}

int insideCircle(point p,point c,int r){	// maybe coo is integer
  double dx = p.x - c.x, dy = p.y - c.y;
  double Euc = dx * dx + dy * dy, rSq = r * r;
  return Euc < rSq ? 0 : Euc == rSq ? 1 : 2; //inside/border/outside
}

double rInCircle(double ab, double bc, double ca) {
  return area(ab, bc, ca) / (0.5 * perimeter(ab, bc, ca));
}

double rInCircle(point a,point b,point c) {
  return rIncircle(dist(a,b),dist(b,c),dist(c,a));
}

// assumption: the required points/lines functions have been written
// returns 1 f there is an inCircle center, returns 0 otherwise
// if this function returns 1, ctr will be the inCircle center
// and r is the same as rInCircle
int inCircle(point p1,point p2,point p3, point& ctr, double &r) {
  r = rInCircle(p1, p2, p3);
  if(fabs(r) < EPS) return 0;	// no inCircle center
  
  line l1, l2;	//compute these two angle bisectors
  double ratio = dist(p1, p2) / dist(p1, p3);
  point p = translate(p2, scale(toVec(p2, p3),ratio / (1 + ratio)));
  pointsToLine(p1, p, l1);
  
  ratio = dist(p2, p1) / dist(p2, p3);
  point p = translate(p1, scale(toVec(p1, p3),ratio / (1 + ratio)));
  pointsToLine(p2, p, l2);
  
  areIntersect(l1, l2, ctr);
  return 1;
}

double rCircumCircle(double ab,double bc,double ca) {
  return ab * bc * ca / (4.0 * area(ab, bc, ca));
}

double rCircumCircle(point a,point b,point c) {
  return rCircumCircle(dist(a,b), dist(b,c), dist(c,a));
}

// returns the perimeter, which is the sum of Euclidian distances
// of consecutive line segments (polygon edges)
double perimeter(const vector<point> &P) {
  double result = 0.0;
  for(int i = 0; i < (int)P.size()-1; i++) //remember that P[0] = P[n-1]
    result += dist(P[i], P[i+1]);
  return result;
}

// return the area, which is half the determinant
double area(const vector<point> &P) {
  double result = 0.0, x1, y1, x2, y2;
  for (int i = 0; i < (int)P.size()-1; i++) {
    x1 = P[i].x; x2 = P[i+1].x;
    y1 = P[i].y; y2 = P[i+1].y;
    result += (x1 * y2 - x2 * y1);
  }
  return fabs(result) / 2.0;
}

bool isConvex(const vector<point> &P) {		//returns true if all three
  int sz = (int)P.size();		// consecutive vertices of P form the same turns
  if (sz <= 3) return false;	// a point/sz=2 or a line/sz=3 is not convex
  bool isLeft = ccw(P[0], P[1], P[2]);	// remember one result
  for(int i = 1; i < sz-1; i++)		// then compare with the others
    if(ccw(P[i], P[i+1], P[(i+2) == sz ? 1 : i+2]) != isLeft)
      return false;		// different sign -> this polygon is concave
  return true;							// this polygon is convex
}

//returns true if point p is in either convex/concave polygon P
bool inPolygon(point pt, const vector<point> &P) {
  if((int)P.size() == 0) return false;
  double sum = 0;	// assume the first vertex is equal to the last vertex
  for (int i = 0; i< (int)P.size()-1; i++) {
    if (ccw(pt, P[i], P[i+1]))
      sum += angle(P[i], pt, P[i+1]);	// left turn/ccw
    else
      sum -= angle(P[i], pt, P[i+1]);	// right turn/cw
  }
  return fabs(fabs(sum) - 2*PI) < EPS;
}

// line segment p-q intersect with line A-B
point lineIntersectSeg(point p, point q, point A, point B) {
  double a = B.y - A.y;
  double b = A.x - B.x;
  double c = B.x * A.y - A.x * B.y;
  double u = fabs(a * p.x + b * p.y + c);
  double v = fabs(a * q.x + b * q.y + c);
  return point((p.x * v + q.x * u) / (u+v) , (p.y * v + q.y * u) / (u+v));
}

// cuts polygon Q along the line formed by point a -> point b
// (note: the last point must be the same as the first point)
vector<point> cutPolygon(point a, point b, const vector<point> &Q) {
  vector<point> P;
  for (int i = 0; i < (int)Q.size(); i++) {
    double left1 = cross(toVec(a,b) , toVec(a,Q[i])), left2 = 0;  
    if(i != (int)Q.size()-1)
      left2 = cross(toVec(a,b) , toVec(a, Q[i+1]));
    if(left1 > -EPS)		// Q[i] is on the left of ab
      P.push_back(Q[i]);
    if(left1 * left2 < -EPS)	// edge (Q[i], Q[i+1]) crosses line ab
      P.push_back(lineIntersectSeg(Q[i], Q[i+1],a,b));
  }
  if(!P.empty() && !(P.back() == P.front()))
    P.push_back(P.front());		//make P's first point = P's last point
  return P;
}

point pivot(0,0);
bool angleCmp(point a, point b) {	// angle-sorting function
  if(collinear(pivot, a, b))	// special case
    return dist(pivot, a) < dist(pivot, b);	// check which one is closer
  double d1x = a.x - pivot.x, d1y = a.y - pivot.y;
  double d2x = b.x - pivot.x, d2y = b.y - pivot.y;
  return (atan2(d1y, d1x) - atan2(d2y, d2x)) < 0;	// compare two angles
}

vector<point> CH(vector<point> P) {	// the content of P may be reshuffled
  int i, j, n = (int)P.size();
  if(n <= 3) {
    if(!(P[0] == P[n-1]))
      P.push_back(P[0]);		// safeguard from corner case
    return P;				// special case, the CH is P itself
  }
  
  // first, find P0 = point with lowest Y and if tie: rightmost X
  int P0 = 0;
  for(int i = 1; i < n; i++)
    if(P[i].y < P[P0].y || (P[i].y == P[P0].y && P[i].x > P[P0].x))
      P0 = i;
      
  point temp = P[0]; P[0] = P[P0]; P[P0] = temp; // swap P[P0] with P[0]
    
  // second, sort points by angle w.r.t. pivot P0
  pivot = P[0];
  sort(++P.begin(), P.end(), angleCmp);		// we do not sort P[0]
  // to be continued
  
  // cotinuation from the earlier part
    // third, the ccw tests
  vector<point> S;
  S.push_back(P[n-1]); S.push_back(P[0]); S.push_back(P[1]);  // initial S
  i = 2;			// then, we check the rest
  while(i < n) {		// note: N must be >= 3 for this method to work
    j = (int)S.size()-1;
    if(ccw(S[j-1], S[j], P[i]))
      S.push_back(P[i++]);		// left turn, accept
    else
      S.pop_back();	// or pop the top of S until we have a left turn
  }
  return S;		// return result
}

#include <bitset>	// compact STL for Sieve, better than vector<bool>!
ll _sieve_size;		
bitset<10000010> bs;	// 10^7 should be enough for most cases
vi primes

void sieve(ll upperbound) {	// create list of primes in [0..upperbound]
  _sieve_size = upperbound + 1;	// add 1 to include upperbound
  bs.set();		// set all bits to 1
  bs[0] = bs[1] = 0;	// except index 0 and 1
  for (ll i = 2; i <= _sieve_size; j += i) if(bs[i]) {
    //cross out multiples of i starting from i * i!
    for (ll j = i * i; j <= _sieve_size; j += i) bs[j] = 0;
    primes.push_back((int)i);	// add this prime to the list of primes
  }	// call this method in main method
}

bool isPrime(ll N) {	// a good enough deterministic prime tester
  if (N <= _sieve_size) return bs[N];	// O(1) for small primes
  for( int i = 0; i < (int)primes.size(); i++)
    if(N % primes[i] == 0) return false;
  return true;	// it takes longer time if N is a large prime!
}		// note: only work for N <= (last prime in vi "primes")^2

int gcd(int a,int b) { return b == 0 ? a : gcd(b, a % b);}
int lcm(int a,int b) { return a* (b / gcd(a, b));}

vi primeFactors(ll N) {
  vi factors;
  ll PF_idx = 0, PF = primes[PF_idx];	// primes has been populated by sieve
  while(PF * PF <= N) {			// stop at sqrt(N) : N can get smaller
    while(N % PF == 0) { 
	  N /= PF; 				// remove PF
	  factors.push_back(PF);
	}
	PF = primes[++PF_idx];	// only consider primes!
  }
  if(N != 1)factors.push_back(N)	// special case if N is a prime
  return factors;	// if N does not fit in 32-bit integer and is a prime
}					// then 'factors' will have to be changed to vector<ll>

// store x, y, and d as global variables
void extendedEuclid(int a, int b) {
  if (b == 0) { x = 1; y = 0; d = a; return; } // base case
  extendedEuclid(b, a % b);
  int x1 = y;
  int y1 = x - (a / b) * y;
  x = x1;
  y = y1;
}

// returns mu is the start of cycle and lambda is length of cycle
ii floydCycleFinding(int x0) { // Function int f(int x) is defined earlier
  // 1st part: finding k*mu, hare's speed is 2x tortoise's
  int tortoise = f(x0), hare = f(f(x0));	// f(x0) is the node next to x0
  while (tortoise != hare) { tortoise = f(tortoise); hare = f(f(hare));}
  // 2nd part: finding mu, hare and tortoise move at the same speed
  int mu = 0;hare = x0;
  while (tortoise != hare) { tortoise = f(tortoise); hare = f(hare); mu++; }
  // 3rd part: finding lambda, hare moves, tortoise stays
  int lambda = 1; hare = f(tortoise);
  while(tortoise != hare) { hare = f(hare); lambda++;}
  return ii(mu, lambda);
}

void solve(){
	
  // 6 points, entered in counter clockwiss order, 0-based indexing
  vector<point> P;
  P.push_back(point(1, 1));	//P0
  P.push_back(point(3, 3));	//P1
  P.push_back(point(9, 1));	//P2
  P.push_back(point(12, 4));	//P3
  P.push_back(point(9, 7));	//P4
  P.push_back(point(1, 7));	//P5
  P.push_back(P[0]); // important: loop back
  
}
