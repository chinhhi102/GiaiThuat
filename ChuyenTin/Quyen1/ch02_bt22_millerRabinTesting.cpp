#include<bits/stdc++.h>
using namespace std;
#define int long long
#define COMPOSITE false
#define PRIME true

int modPower(int a, int b, int p){
	if(b == 1) return a; // a^1 = a
	int x = modPower(a, b/2, p);
	if(b&1) return (x%p) * (x%p) * (a%p) % p;
	else	return (x%p) * (x%p) % p;
}
pair<int,int> Decompose(int p){
	int i = 0;
	while(p%2 == 0) i++, p /= 2;
	return {i, p};
}
bool Witness(int a, int N){
	int k,m;
	tie(k, m) = Decompose(N - 1); // find k,m with (N - 1 = (2^k)*m
	int x, y = modPower(a, m, N);
	if(y == 1) return PRIME;
	for(int i = 1; i <= k; i++){
		x = y * y % N;
		if(x == 1)
			if(y == (N - 1)) return PRIME; // if a^((2^k)*m) == 1 and a^((2^(k-1))*m) == - 1 then => PRIME
			else			 return COMPOSITE;
		y = x;
	}
	return COMPOSITE;	// if dont exist then => COMPOSITE
}
bool millerRabinTesting(int N, int k){
	if(N < 2)
		return COMPOSITE;
	if(N == 2 || N == 3)
		return PRIME;
	bool WITNESS = PRIME;
	while(k--){ // check k times
		int a = rand() % (N - 3) + 2; // call a is random number between 2 and N - 1
		if(__gcd(a, N) != 1) return COMPOSITE;  // if gcd(a, N) != 1 then N % a != 1 => COMPOSITE
		if(modPower(a, N - 1, N) != 1) return COMPOSITE; // if a^(N-1) % N != 1 => COMPOSITE
		WITNESS = Witness(a, N);
		if(!WITNESS)
			return COMPOSITE;
	}
	return PRIME;
}
#undef int
int main(){
#define int long long
	int N, k = 5;
	cout << "Nhap N : ";
	cin >> N;
	cout << "N " << (millerRabinTesting(N, k) ? "is" : "isn't") << " Prime!" << endl;
}
