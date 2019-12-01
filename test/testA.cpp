#include<bits/stdc++.h>
using namespace std;
#define oo 10000000007
#define int long long
int sqDist(int x0, int y0, int x, int y){
	int dx = x0 - x;
	int dy = y0 - y;
	return dx*dx + dy*dy;
}
#undef int
int main(){
#define int long long
	int x0, y0, R;
	int x1, y1, x2, y2;
	cin >> x0 >> y0 >> R >> x1 >> y1 >> x2 >> y2;
	int d = __gcd(abs(x2 - x1), abs(y2 - y1));
	int dx = (x2 - x1) / d;
	int dy = (y2 - y1) / d;
	int lo = -3000000000;
	int hi = 3000000000;
	int minM = hi;
	int minD = oo;
	while(lo <= hi){
		int m1 = (2*lo + hi) / 3;
		int m2 = (lo + 2*hi) / 3;
		
		int a1 = x1 + m1*dx;
		int b1 = y1 + m1*dy;
		int d1 = sqDist(x0, y0, a1, b1);
		
		int a2 = x1 + m2*dx;
		int b2 = y1 + m2*dy;
		int d2 = sqDist(x0, y0, a2, b2);
		
		if(d1 < minD){
			minD = d1;
			minM = m1;
		}
		if(d2 < minD){
			minD = d2;
			minM = m2;
		}
		if(d1 <= d2){
			hi = m2 - 1;
		}
		if(d1 >= d2){
			lo = m1 + 1;
		}
	}
	if(minD > R*R)
		cout << 0;
	else{
		lo = minM;
		hi = 3000000000;
		int upper = minM;
		while(lo <= hi){
			int mid = (lo + hi) / 2;
			int a = x1 + mid*dx;
			int b = y1 + mid*dy;
			int d = sqDist(x0, y0, a, b);
			
			if(d <= R*R){
				upper = mid;
				lo = mid + 1;
			}else{
				hi = mid - 1;
			}
		}
		
		lo = -3000000000;
		hi = minM;
		int lower = minM;
		while(lo <= hi){
			int mid = (lo + hi) / 2;
			int a = x1 + mid*dx;
			int b = y1 + mid*dy;
			d = sqDist(x0, y0, a, b);
			
			if(d <= R*R){
				lower = mid;
				hi = mid - 1;
			}else{
				lo = mid + 1;
			}
		}
		cout << upper - lower + 1;
	}
}
