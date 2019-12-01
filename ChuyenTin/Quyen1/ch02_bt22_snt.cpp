#include<bits/stdc++.h>
using namespace std;
#define MAXN 1000010
#define int long long
bitset<MAXN> isPrime;
vector<int> Primes;
void sieve_Eratosthene(){
	isPrime.set();
	isPrime[0] = isPrime[1] = 0;
	for(int i = 4; i < MAXN; i += 2) isPrime[i] = 0;
	Primes.push_back(2);
	for(int i = 3; i < MAXN; i += 2){
		if(isPrime[i]){
			for(int j = i*i ; j < MAXN; j += i) isPrime[i] = 0;
			Primes.push_back(i);
		}
	}
}
vector<pair<int,int>> PFs; // a^i
int couting_Divisor(int N){
	int res = 1;
	int index_PF = 0, PF = Primes[index_PF];
	int d = 0;
	while(PF*PF <= N){
		while(N%PF == 0){ d++, N /= PF;	}
		if(d)
			PFs.push_back({PF, d}), d = 0;
		PF = Primes[++index_PF];
	}
	if(N != 1)
		PFs.push_back({N, 1});
	for(int i = 0; i < PFs.size(); i++)
		res = res * (PFs[i].second + 1);
	return res;
}
int sumOfDivisor(int N){
	int res = 1;
	for(int i = 0; i < PFs.size(); i++)
		res = res * ((pow(PFs[i].first, PFs[i].second + 1) - 1)/(PFs[i].first - 1)); // (a^(i+1) - 1) / (a - 1)
	return res;
}
#undef int
int main(){
#define int long long
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	sieve_Eratosthene();
	int n;
	cin >> n;
	cout << couting_Divisor(n) << endl;
	cout << sumOfDivisor(n) << endl;
}
