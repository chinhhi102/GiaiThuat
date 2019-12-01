#include<bits/stdc++.h>
using namespace std;
int tow[4] = {};
int k;
void move(int n, int src, int dst, int tmp){
	if(k == 0) return;
	if(n == 1){
		tow[src]--;
		tow[dst]++;
		k--;
	}
	else{
		move(n - 1, src, tmp, dst);
		move(1, src, dst, tmp);
		move(n - 1, tmp, dst, src);
	}
}
int main(){
	int n;
	cin >> n >> k;
	tow[1] = n;
	move(n, 1, 2, 3);
	cout << tow[1] << ' ' << tow[2] << ' ' << tow[3] << endl;
}
