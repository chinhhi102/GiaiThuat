#include<bits/stdc++.h>
using namespace std;
int main(){
#define int long long
	int n;
	cin >> n;
	int a[n + 1];
	for(int i = 1; i <= n; i++) cin >> a[i];
	int uc = a[1];
	int bc = 1;
	for(int i = 2; i <= n; i++) uc = __gcd(uc, a[i]);
	for(int i = 1; i <= n; i++) bc = bc * (a[i] / __gcd(bc, a[i]));
	cout << uc << endl << bc << endl;
}
