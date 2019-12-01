#include<bits/stdc++.h>
using namespace std;
// tinh so fibonacci thu N

int F ( int n) {
	if (n<=2) 
	return 1;
	return F(n-1) + F(n-2);
}
int main () 
{
	int n;
	cout <<" nhap n: ";
	cin>>n; 
	cout <<" So Fibonacci cua :" <<n<< "la :" <<F(n);
	return 0;
} 




