#include<bits/stdc++.h>
using namespace std;
int flip(int n){
	int k=n%10;
	while(n/=10){
		k=k*10+n%10;
	}
	return k;
}
int main(){
	int a,b;
	scanf("%d%d",&a,&b);
	a=flip(a);
	b=flip(b);
	a>b?printf("%d",a):printf("%d",b);
}
