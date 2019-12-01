#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin >> n;
	int t = 1, res = 0, div = 5;
	while(div <= n){
		res += n / div;
		div = pow(5, ++t);
	}
	cout << res << endl;
}
