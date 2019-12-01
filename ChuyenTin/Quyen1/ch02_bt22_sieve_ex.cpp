#include<bits/stdc++.h>
using namespace std;
#define MAXN 1000010
#define int long long
bitset<MAXN> isPrime;
vector<int> primes;
void sieve_Eratosthene(){ // sieve primes 10^7
	isPrime.set();
	isPrime[0] = isPrime[1] = 0;
	primes.push_back(2);
	for(int i = 4; i < MAXN; i += 2)
		isPrime[i] = 0;
	for(int i = 3; i < MAXN; i += 2){
		if(isPrime[i]){
			primes.push_back(i);
			for(int j = i*i; j < MAXN; j += i){
				isPrime[j] = 1;
			}
		}
	}
}

vector<pair<int,int>> PF;
void calc_PF(int N){
	int PF_index = 0, nPF = primes[PF_index];
	int d = 0;
	while(nPF*nPF <= N){
		while(N % nPF == 0){
			N /= nPF;
			d++;
		}
		if(d)
			PF.push_back({nPF,d});
		d = 0;
		nPF = primes[++PF_index];
	}
	if(N != 1)
		PF.push_back({N, 1});
	for(int i = 0; i < PF.size(); i++){
		cout << PF[i].first << "^" << PF[i].second << (i == PF.size() - 1 ? " \n" : " x ");
	}
}

void couting_Divisor(int N){
	int Total = 1;			// Counting: (i + 1) x (j + 1) x ... (k + 1) with i, j, k is a^i x b^j x ... x m^k
	for(int i = 0; i < PF.size(); i++)
		Total *= (PF[i].second + 1);
	cout << "Number of Divisor of N : " << Total << endl;
}

void sum_Divisor(int N){
	int Sum = 1;			// Sum:  ((a^(i+1)-1)/(a-1)) x ((b^(j+1)-1)/(b-1)) x ... x ((m^(k+1)-1)/(m-1))
	for(int i = 0; i < PF.size(); i++)
		Sum *= (pow((PF[i].first),(PF[i].second + 1)) - 1) / (PF[i].first - 1);
	cout << "Sum of Divisor of N : " << Sum << endl;
}
#undef int
int main(){
#define int long long
	int N;
	cout << "Nhap N: ";
	cin >> N;
	sieve_Eratosthene();
	calc_PF(N);
	couting_Divisor(N);
	sum_Divisor(N);
}
