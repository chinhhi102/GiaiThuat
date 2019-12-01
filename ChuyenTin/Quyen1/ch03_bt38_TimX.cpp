#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin >> n;
	int a[n];
	for(int i = 0; i < n; i++) 
		cin >> a[i];
	sort(a, a + n);
	if(n&1){
		cout << 1;
	}else{
		cout << a[n / 2 + 1] - a[n / 2] + 1;
	}
}
/*
5
3 1 5 4 5
6
3 1 7 2 5 7
*/
