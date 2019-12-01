#include<bits/stdc++.h>
using namespace std;
int spf[510] = {};
int PFs[510] = {};
#define int long long
void sieve(){
	int n = 500;
	for(int i = 1; i <= n; i++	 ) spf[i] = i;
	for(int i = 2; i <= n; i += 2) spf[i] = 2;
	for(int i = 3; i <= n; i += 2)
		if(spf[i] == i){
			for(int j = i * i; j <= n; j += i)
				if(spf[j] == j) spf[j] = i;
		}
}
#undef int
int main(){
#define int long long
	sieve();
	int n;
	cin >> n;
	for(int i = 1; i <= n; i++){
		int N = i;
		int d = 0;
		int last = 0;
		while(N != 1){
			if(last && last != spf[N]){
				PFs[last] += d;
				d = 0;
			}
			last = spf[N];
			d++;
			N /= spf[N];
		}
		PFs[last] += d;
	}
	int numOfDivisor = 1;
	int sumOfDivisor = 1;
	for(int i = 1; i <= 100; i++){
		if(PFs[i]){
			cout << i << '^' << PFs[i] << " ";
			numOfDivisor *= (PFs[i] + 1);
			sumOfDivisor *= ((pow(i, PFs[i] + 1) - 1)/(i - 1));
		}
	}
	cout << "\nNumber Of Divisor: " << numOfDivisor << endl;
	cout << "Sum Of Divisor: " << sumOfDivisor << endl;
}
