#include<bits/stdc++.h>
using namespace std;
int main(){
	long long n,t(0);
	scanf("%lld",&n);
	for(long long i = 1; i*i<=n;i++){
		if(!(n%i)){
			t+=i;t+=n/i;
		}
		(!(i*i-n))?t-=i:t;
	}
	printf(2*n-t?"NO":"YES");
}
