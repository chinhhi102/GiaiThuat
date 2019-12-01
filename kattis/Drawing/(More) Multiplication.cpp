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

const int INF = 2000000000;
const ll LLINF = 9000000000000000000;

int main(){
	while (1){
		int A,B;
		scanf("%d%d",&A,&B);
		if(!A) break;
		int AB = A*B;
		vi dA,dB,dAB;
		int mA=A, mB= B, mAB = AB;
		while (mA >0) dA.push_back(mA % 10), mA/= 10;
		while (mB >0) dB.push_back(mB % 10), mB/= 10;
		while (mAB>0) dAB.push_back(mAB% 10), mAB/= 10;
		
		int w = 5+dA.size()*4;
		int h = 5+dB.size()*4;
		vector<string> out(h,string(w,' '));
		fora(x,0,w)
			out[0][x]=out[h-1][x]='-';
		for(int y=2;y<h;y+=4)
			fora(x,2,w-2)
				out[y][x]='-';
		fora(y,0,h){
			if (out[y][0]==' ') out[y][0]='|';
			else out[y][0]='+';
			if (out[y][w-1]==' ') out[y][w-1] = '|';
			else out[y][w-1]='+';
		}
		for (int x=2;x<w;x+=4)
			fora(y,2,h-2){
				if (out[y][x]==' ') out[y][x]='|';
				else out[y][x] = '+';
			}
		
		for (int x=2;x<w-3;x+=4)
			for (int y=2;y<h-3;y+= 4)
				out[y+1][x+3]=out[y+2][x+2]=out[y+3][x+1]= '/';
		
		for (int i = int(dA.size())-1,sx=4;i>=0;i--){
			out[1][sx]='0'+dA[i];
			sx+=4;
		}
		for (int i=int(dB.size())-1,sy=4;i>=0;i--){
			out[sy][w-2]='0'+dB[i];
			sy+=4;
		}

		fora(i,0,dA.size())
			fora(j,0,dB.size()){
				int prod=dA[int(dA.size())-1-i]*dB[int(dB.size())-1-j];
				int top=prod/10,bot=prod%10;
				out[3+4*j][3+4*i]='0'+top;
				out[5+4*j][5+4*i]='0'+bot;
			}
		int x=w-6,y=h-2,dx=-4,dy=0;
		bool place=false;
		int rx=2,ry=0;
		int i=0;
		while (i<dAB.size()){
			out[y][x]=dAB[i]+'0';
//			cerr << x << ' '<<y<<endl;
			if (!place) place=true;
			else out[y+ry][x+rx]='/';
			x+=dx;
			y+=dy;
			if (x < 1) {
				x -= dx;
				y -= dy;
				x -= 2;
				y -= 2;
				dx = 0;
				dy = -4;
				rx = 0;
				ry = 2;
			}
			i++;
		}
		
		fora(j,0,h)
			cout<<out[j]<<'\n';
		fflush(stdin);
	}
	return 0;
}
