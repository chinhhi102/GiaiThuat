#include<bits/stdc++.h>
using namespace std;
#define MAXN 1000001
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

int modPower(int a, int b, int p){ // a^b % p
	if(b == 1)
		return a;
	int x = modPower(a, b/2, p);
	if(b&1) // b is odd
		return (x%p) * (x%p) * (a%p) % p; // return x*x*a % p
	return (x%p) * (x%p) % p; // return x*x
}

bool fermatTesting(int N, int k){ // check fermat with k times => O(log^3(N) * k)
	if(N == 2 || N == 3)
		return true;
	while (k--){
		int a = rand() % (N - 3) + 2; // get a is random number between 2 and N - 1
		if(__gcd(a, N) != 1)
			return false;
		else if(modPower(a, N - 1, N) != 1) // [a^(N - 1) != 1 mod N]
			return false;
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
			if(!fermatTesting(i, k)){
				cout<<"Fermat Testing Wrong in : " << i << endl;
				d++;
			}
		if(!isPrime_Era[i])
			if(fermatTesting(i, k)){
				cout << "Fermat Testing " << i << " is Prime Wrong" << endl;
				d++;
			}
	}
	cout << "Fermat check Primes wrong " << d << " times when testing " << k << " times"<<endl;
	}
}
