#include<bits/stdc++.h>
using namespace std;
#define int long long

#undef int
int main(){
#define int long long
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int T;
	cin >> T;
	while(T--){
	int a, b;
	cin >> a >> b;
	cout << (__gcd(a, b) == 1 ? "Finite" : "Infinite") << endl;
		}	
}
