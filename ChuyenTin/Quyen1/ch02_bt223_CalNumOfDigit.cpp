#include<bits/stdc++.h>
using namespace std;

#define int long long
#define base 10000000
#define nmax 102

struct bigNum{
	int sl = 0;
	int h[22] = {};
};

string s;
int n;
bigNum F[nmax][nmax];
bigNum res[10];

bigNum add(bigNum a, bigNum b){
	bigNum sol;
	int sum, hold = 0;
	sol.sl = max(a.sl, b.sl);
	for(int i = 1; i <= sol.sl; i++){
		sum = a.h[i] + b.h[i] + hold;
		hold = sum / base;
		sol.h[i] = sum % base;
	}
	if(hold){
		sol.sl++;
		sol.h[sol.sl] = hold;
	}
	return sol;
}

bigNum mul(bigNum a, int b){
	bigNum sol;
	int sum, hold = 0;
	sol.sl = a.sl;
	for(int i = 1; i <= sol.sl; i++){
		sum = a.h[i] * b + hold;
		hold = sum / base;
		sol.h[i] = sum % base;
	}
	while(hold){
		sol.h[++sol.sl] = hold % base;
		hold /= base;
	}
	return sol;
}

void init(){
	F[0][0].sl = F[0][0].h[1] = 1;
	for(int i = 1; i <= n; i++){
		for(int j = 0; j <= i; j++){
			F[i][j] = mul(F[i - 1][j], 9);
			if(j) F[i][j] = add(F[i][j], F[i - 1][j - 1]);
		}
	}
}

bigNum cal(int digit, int sum){
	bigNum sol;
	for(int i = 1; i <= n; i++){
		int cur = s[i - 1] - '0';
		for(int ch = 0; ch < cur; ch++){
			if(ch == digit && sum > 0) sol = add(sol, F[n - i][sum - 1]);
			else if(ch != digit) sol = add(sol, F[n - i][sum]);
		}
		sum -= (digit == cur);
		if(sum < 0) break;
	}
	return sol;
}

bigNum cal0(int digit, int sum){
	bigNum sol;
	int ss = sum;
	for(int i = 1; i <= n; i++){
		int cur = s[i - 1] - '0';
		for(int ch = 0; ch < cur; ch++){
			if(ch > 0 || i > 1){
				if(ch == digit && sum > 0) sol = add(sol, F[n - i][sum - 1]);
				else if(ch != digit) sol = add(sol, F[n - i][sum]);
			}
		}
		sum -= (digit == cur);
		if(sum < 0) break;
	}
	sum = ss;
	for(int i = 2; i <= n; i++)
		if(n - i >= sum) sol = add(sol, mul(F[n - i][sum], 9));
	return sol;
}

void printResult(bigNum s){
	if(s.sl == 0){
		cout << 0 << endl;
		return;
	}
	cout << s.h[s.sl];
	for(int i = s.sl - 1; i > 0; i--){
		if(s.h[i] == 0) cout << "0000000";
		else{
			int d = 0, j = s.h[i];
			while(j){
				d++;
				j /= 10;
			}
			d = 7 - d;
			while(d--) cout << '0';
			cout << s.h[i];
		}
	}
	cout << endl;
}

void process(){
	cin >> s;
	n = s.size();
	bigNum sol;
	init();
	for(int i = 1; i <= 9; i++){
		for(int j = 1; j <= n; j++){
			sol = cal(i, j);
			res[i] = add(res[i], mul(sol, j));
		}
	}
	for(int i = 1; i <= n; i++){
		sol = cal0(0, i);
		res[0] = add(res[0], mul(sol, i));
		int j = s[i - 1] - '0';
		res[j] = add(res[j], F[0][0]);
	}
	for(int i = 0; i <= 9; i++) printResult(res[i]);
}
#undef int
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	process();
}
/*
9999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999
*/
