#include<bits/stdc++.h>
using namespace std;
#define MAXN 10000001
#define int long long
bitset<MAXN> isPrime_Era;
void sieve_Eratosthene(){
	isPrime_Era.set();
	isPrime_Era[0] = isPrime_Era[1] = 0;
	for(int i = 4; i < MAXN; i += 2)
		isPrime_Era[i] = 0;
	for(int i = 3; i < MAXN; i += 2){
		if(isPrime_Era[i]){
			for(int j = i*i; j < MAXN; j += i){
				isPrime_Era[j] = 0;
			}
		}
	}
}

int modPower(int a, int b, int p){
	if(b == 1)
		return a;
	int x = modPower(a, b/2, p);
	if(b&1)	return (x%p) * (x%p) * (a%p) % p;
	else	return (x%p) * (x%p) % p;
}

pair<int,int> Decompose(int p){
	int i = 0;
	while(p%2 == 0) i++, p /= 2;
	return {i, p};
}

bool Witness(int a, int N){
	int k,m;
	tie(k,m) = Decompose(N - 1);  // N - 1 = (2^k)*m
	int b[k+1];
	b[0] = modPower(a, m, N);
	if(b[0] == 1)
		return true;
	for(int i = 1; i <= k; i++){
		b[i] = b[i - 1] * b[i - 1] % N;
		if(b[i] == 1)
			if(b[i - 1] == N - 1) return true;
			else 				return false;
	}
	return false;
}

bool millerRabinTesting(int N, int k){
	if(N == 2 || N == 3)
		return true;
	if(N < 2)
		return false;
	while(k--){
		bool WITNESS = true;
		int a = rand() % (N - 3) + 2;
		if(__gcd(a, N) != 1) // if gcd(a, N) != 1 -> COMPOSITE
			return false;
		else if(modPower(a, N - 1, N) != 1) // if (a^(N-1) != 1 mod N -> COMPOSITE
			return false;
		else{
			WITNESS = Witness(a, N); 
			if(!WITNESS)
				return false;
		}
	}
	return true;
}

#undef int
int main(){
#define int long long
	sieve_Eratosthene();
	int d = 0;
	int k;
	for(int k = 1; k < 50; k++){ d = 0;
	for(int i = 2; i < MAXN; i++){
		if(isPrime_Era[i])
			if(!millerRabinTesting(i, k)){
				cout<<"Miller Rabin Testing Wrong in : " << i << endl;
				d++;
			}
		if(!isPrime_Era[i])
			if(millerRabinTesting(i, k)){
				cout << "Miller Rabin Testing " << i << " is Prime Wrong" << endl;
				d++;
			}
	}
	cout << "Miller Rabin check Primes wrong " << d << " times when testing " << k << " times"<<endl;
	}
}
