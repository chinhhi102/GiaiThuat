#include<bits/stdc++.h>
using namespace std;
int main(){
#define int long long
	int n, m, k;
	cin >> n >> m >> k;
	int res = 1;
	int mod = 1;
	string result = "";
	for(int i = 1; i <= k; i++) mod *= 10;
	for(int i = 1; i <= n; i++) res = (res*m) % mod;
	for(int i = 1; i <= k; i++) result = char(res%10 + '0') + result, res /= 10;
	cout << result << endl;
}
