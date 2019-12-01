#include<bits/stdc++.h>
using namespace std;
int modPower(int a, int b, int p){
	if(b == 1) return a;
	int x = modPower(a, b/2, p);
	if(b&1) return (x%p) * (x%p) * (a%p) % p;
	else	return (x%p) * (x%p) % p;
}
pair<int,int> deCompose(int p){
	int i = 0;
	while(p%2 == 0) i++, p /= 2;
	return {i, p};
}
bool witness(int a, int N){
	int k,m;
	tie(k,m) = deCompose(N - 1);
	int x, y = modPower(a, m, N);
	if(y ==  1) return true;
	for(int i = 1; i <= k; i++){
		x = y * y % N;
		if(x == 1)
			if(y == N - 1)  return true;
			else			return false;
		y = x;
	}
	return false;
}
bool millerRabinTesting(int N, int k){
	if(N < 2) return false;
	else if(N == 2 || N == 3) return true;
	bool kt = true;
	while(k--){
		int a = rand() % (N - 3) + 2;
		if(__gcd(N, a) != 1) return false;
		if(modPower(a, N - 1, N) != 1) return false;
		kt = witness(a, N);
		if(!kt)
			return false;
	}
	return true;
}
int main(){
	int l, r;int d=0;
	cin >> l >> r;
	for(int i = l; i <= r; i++)
		if(millerRabinTesting(i, 5)){d++;
			cout << i << endl;}
	cout << d;
}
