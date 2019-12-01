#include<bits/stdc++.h>
using namespace std;
#define MAXN 1000010
#define int long long
int spf[MAXN];
void sieve_Eratosthene(){
	spf[1] = 1;
	for(int i = 2; i   < MAXN; i++   ) spf[i] = i;
	for(int i = 4; i   < MAXN; i += 2) spf[i] = 2;
	for(int i = 3; i*i < MAXN; i += 2){
		if(spf[i] == i){
			for(int j = i*i; j < MAXN; j += i){
				if(spf[j] == j)
					spf[j] = i;
			}
		}
	}
}
vector<pair<int,int>> PF; // a^i
void calc_PF(int N){ // Find PF with O(log N) N < 10^7
	int d = 0;
	int last = 0;
	while(N != 1){
		if(last && last != spf[N]){
			PF.push_back({last, d});
			d = 0;
		}
		last = spf[N];
		d++;
		N = N / spf[N];
	}
	PF.push_back({last , d});
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
