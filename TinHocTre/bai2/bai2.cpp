#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin>>n;
//	for(n=0;n<=100;n++)
	cout<<11000+(n>29?28*12000:(n-1)*12000)+(n>29?(n-29)*10000:0)<<endl;
	return 0;
}
