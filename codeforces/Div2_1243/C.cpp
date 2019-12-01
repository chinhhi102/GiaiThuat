#include<bits/stdc++.h>
using namespace std;
int main(){
#define int long long
	int n;
	cin >> n;
	int res = 0;
	for(int i = 2; i <= sqrt(n); i++){
		if(n%i == 0){
			if(!res) res = i;
			res = __gcd(res, i);
			res = __gcd(res, n/i);
		}
	}
	cout << (res ? res : n) << endl;
}
