#include<bits/stdc++.h>
using namespace std;
#define nmax 102
#define base (int)1e7
#define int long long
struct bigNum{
	int sl = 0;
	int h[21] = {};
};

string s;
int n;
bigNum res[10];
bigNum F[nmax][nmax];

bigNum add(bigNum a, bigNum b){
	int sum = 0, hold = 0;
	bigNum c;
	c.sl = max(a.sl, b.sl);
	for(int i = 1; i <= c.sl; i++){
		sum = a.h[i] + b.h[i] + hold;
		c.h[i] = sum % base;
		hold = sum / base;
	}
	if(hold){
		c.sl++;
		c.h[c.sl] = hold;
	}
	return c;
}

bigNum mul(bigNum a, int b){
	int sum, hold = 0;
	bigNum c;
	c.sl = a.sl;
	for(int i = 1; i <= c.sl; i++){
		sum = a.h[i] * b + hold;
		c.h[i] = sum % base;
		hold = sum / base;
	}
	while(hold){
		c.sl++;
		c.h[c.sl] = hold % base;
		hold /= base;
	}
	return c;
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
	sol.sl = 0;
	for(int i = 1; i <= n; i++){
		int cur = s[i - 1] - '0';
		for(int ch = 0; ch < cur; ch++){
			if((ch == digit) && (sum > 0)) sol = add(sol, F[n - i][sum - 1]);
			else if(ch != digit) sol = add(sol, F[n - i][sum]);
		}
		sum -= (cur == digit);
		if(sum < 0) break;
	}
	return sol;
}

bigNum cal0(int digit, int sum){
	bigNum sol;
	sol.sl = 0;
	int ss = sum;
	for(int i = 1; i <= n; i++){
		int cur = s[i - 1] - '0';
		for(int ch = 0; ch < cur; ch++){
			if((ch > 0) || (i > 1)){
				if((ch == digit) && (sum > 0)) sol = add(sol, F[n - i][sum - 1]);
				else if(ch != digit) sol = add(sol, F[n - i][sum]);
			}
		}
		sum -= (cur == digit);
		if(sum < 0) break;
	}
	sum = ss;
	for(int i = 2; i <= n; i++){
		if(n - i >= sum)
			sol = add(sol, mul(F[n - i][sum], 9));
	}
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
			int j = s.h[i];
			int d = 0;
			while(j){
				d++;
				j /= 10;
			}
			for(int j = 1; j <= 7 - d; j++) cout << '0';
			cout << s.h[i];
		}
	}
	cout << endl;
}

void process(){
	bigNum sol;
	cin >> s;
	n = s.size();
	init();
	for(int i = 1; i <= 9; i++)
		for(int j = 1; j <= n; j++){
			sol = cal(i, j);
			res[i] = add(res[i], mul(sol, j));
		}
	for(int i = 1; i <= n; i++){ 
		sol = cal0(0, i);
		res[0] = add(res[0], mul(sol, i));
	}
	for(int i = 1; i <= n; i++){
		int j = s[i - 1] - 48;
		res[j] = add(res[j], F[0][0]);
	}
	for(int i = 0; i <= 9; i++) printResult(res[i]);
}
#undef int
int main(){
#define int long long
	process();
}