#include<bits/stdc++.h>
using namespace std;
/*
X = {x1, x2, ..., xk}
Xi = {1, 2, ..., n}
xi < x(i+1)
Gia su n = 4, k = 3
1 2 3
1 2 4
1 3 4
2 3 4
x1 = {1, 2} // 3 = 4 - 2 + 1
x2 = {2, 3} // n - k + 2 = 4 - 3 + 2 = 3
x3 = {3, 4} // 
x2 = {2, 3, 4} // 4 = 4 - 2 + 2
x1 = {1 ... n - k + 1} 
x2 = {2 ... n - k + 2}
...
xi = {i ... n - k + i}
*/
int X[1000] = {}; // Tap nghiem X
int n, k;
void xuat(){
	for(int i = 1; i <= k; i++)
		cout << X[i] << ' ';
	cout << endl;
}
void backtrack(int i){ // Xay dung tp thu i
	// Tim tap j = xi
	for(int j = X[i - 1]; j <= n - k + i; j++){
		X[i] = j;  // Ghi nhan Xi
		if(i == k){ // Da tim duoc tap nghiem
			xuat();
		}else backtrack(i + 1);
	}
}
int main(){
	cin >> n >> k;
	backtrack(1);
}
