#include<bits/stdc++.h>
using namespace std;
int main(){
	long long x,n,tmp(1);
	scanf("%lld%lld",&x,&n);
	while(n>1){
		if(n%2) tmp=(tmp*x)%10000;
		x=(x*x)%10000;
		n/=2;
	}
	printf("%lld",x*tmp%10000);
}
