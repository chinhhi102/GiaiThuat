#include<bits/stdc++.h>
using namespace std;
int d[11] = {};
void c(int a){
	while(a){
		d[a%10]++;
		a/=10;
	}
}
int main(){
	int n;
	cin >> n;
	for(int i = 1; i <= n; i++)
		c(i);
	for(int i = 0; i <= 9; i++)
		cout << i << " = " << d[i] << endl;
}
