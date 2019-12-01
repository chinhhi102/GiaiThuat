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
#define fora(i,a,b) for(int i=a;i<=b;i++)
#define fors(i,a,b) for(int i=a;i>=b;i--)
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
typedef pair<int,int> pi;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<bool> vb;
typedef vector<vector<int> > vvi;
typedef map<int,int> mi;
typedef map<long,long> mll;

typedef struct point pnt;
typedef struct triangle tri;

struct point{
	int x,y;
};

struct triangle{
	pnt a,b,c;
};

int double_area(tri* t){
    return t->a.x * t->b.y + t->b.x * t->c.y + t->c.x * t->a.y - t->b.x * t->a.y - t->c.x * t->b.y - t->a.x * t->c.y;
}

int left_of(pnt* p0, pnt* p1, pnt* p2){
    return (p1->x - p0->x) * (p2->y - p0->y) - (p2->x - p0->x) * (p1->y - p0->y) > 0;
}

int inside(tri* t, pnt* p){
    return !left_of(&t->a, &t->b, p) && !left_of(&t->b, &t->c, p) && !left_of(&t->c, &t->a, p);
}

int main(){
	io;
	tri t;
	scanf("%d%d%d%d%d%d",&t.a.x,&t.a.y,&t.b.x,&t.b.y,&t.c.x,&t.c.y);
	int a=double_area(&t);
	if (a<0)a=-a;
    else{
        if(t.b.x-t.c.x) t.b.x^=t.c.x^=t.b.x^=t.c.x;
        if(t.b.y-t.c.y) t.b.y^=t.c.y^=t.b.y^= t.c.y;
    }
    printf(a&1?"%d.5\n":"%d.0\n",a>>1);
	int n,res(0);sc(n);
	while(n--){
		pnt p;
		sc(p.x);sc(p.y);
		if(inside(&t,&p))res++;
	}
	printf("%d",res);
	return 0;
}
