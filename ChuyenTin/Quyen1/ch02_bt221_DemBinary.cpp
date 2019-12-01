#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin >> n;
	int s1 = 2, s2 = 3, s3;
	for(int i = 2; i <= n; i++){
		s3 = s1 + s2;
		s1 = s2;
		s2 = s3;
	}
	cout << s1;
}
