#include<bits/stdc++.h>
using namespace std;
int modPower(int a, int b, int p){
	if(b == 1) return a;
	int x = modPower(a, b/2, p);
	if(b%2 == 0) return (x*x) % p;
	return (x*x*a) % p;
}
pair<int,int> Decompose(int p){
	int i = 0;
	while(p%2 == 0){ p /= 2; i++; }
	return {i, p};
}
bool witness(int a, int N){
	int m, k;
	tie(k, m) = Decompose(N - 1);
	int y, x = modPower(a, m, N);
	if(x == 1) return true;
	for(int i = 1; i <= k; i++){
		y = x*x % N;
		if(y == 1)
			if(x == N - 1)  return true;
			else			return false;
		x = y;
	}
	return false;
}
bool MillerRabinTesting(int n, int k){
	if(n < 2) return false;
	if(n == 2 || n == 3) return true;
	while(k--){
		int a = rand() % (n - 3) + 2;
		if(__gcd(n, a) != 1) return false;
		if(modPower(a, n - 1, n) != 1) return false;
		if(!witness(a, n)) return false;
	}
	return true;
}
int main(){
	int l, r;
	cin >> l >> r;
	for(int i = l; i <= r; i++)
		if(MillerRabinTesting(i, 5))
			cout << i << endl;
}
