#include<bits/stdc++.h>
using namespace std;
#define int long long
set<int> res;
bool checkPrime(int n){
	if(n < 2) return false;
	for(int i = 2; i <= sqrt(n); i++)
		if(n % i == 0) return false;
	return true;
}
int str2int(string s, int L) {
	if(L%2 == 0)
		s = s + string(s.rbegin(), s.rend());
	else
		s = s + string(s.rbegin() + 1, s.rend());
	int ret = 0;
	for (int i = 0; i < s.size(); i++)
		ret = 10 * ret + s[i] - '0';
	return ret; 
}
int len(int n) {
	int r = 0;
	do{
		r++;
		n /= 10;
	}while(n);
	return r; 
} 
void doixung(string s, int L, int l, int m) {
	for(char i = '0'; i <= '9'; i++){
		if(i > '0' || s.size()){
			s += i;
			if(s.size()*2 >= L){
				int t = str2int(s, L);
				if(l <= t && t <= m)
					if(checkPrime(t))
						res.insert(t);
			}else doixung(s, L, l, m);
			s.pop_back();
		}
	}
}
#undef int
int main(){
#define int long long
	string s;
	int m, n;
	cin >> m >> n;
	int Lm = len(m);
	int Ln = len(n);
	for(int L = Lm; L <= Ln; L++){
		doixung(s, L, m, n);
	}
	cout << res.size();
}
