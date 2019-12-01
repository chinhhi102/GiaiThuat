#include<bits/stdc++.h>
using namespace std;
#define int long long
#define maxx 1000010
int Fibo[maxx] = {};
#undef int
int main(){
#define int long long
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	string s;
	cin >> s;
	Fibo[0] = 1;
	Fibo[1] = 1;
	for(int i = 2; i < maxx; i++ ){	Fibo[i] = Fibo[i - 1] + Fibo[i - 2]; Fibo[i] %= (int)1e9 + 7;}
	int res = 1;
	int du = 0, dn = 0;
	bool f = 0;
	for(int i = 0; i < s.size(); i++){
		if(s[i] == 'u') du++;
		else{
			res *= Fibo[du];
			res %= (int)1e9 + 7;
			du = 0;
		}
		if(s[i] == 'n') dn++;
		else{
			res *= Fibo[dn];
			res %= (int)1e9 + 7;
			dn = 0;
		}
		if(s[i] == 'm' || s[i] == 'w') f = 1;
	}
	res *= Fibo[du];
	res %= (int)1e9 + 7;
	res *= Fibo[dn];
	res %= (int)1e9 + 7;
	if(f) cout << 0;
	else cout << res;
}
