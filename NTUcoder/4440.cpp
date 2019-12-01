#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,x(9),t(0);
	long long res(0);
	scanf("%d",&n);
	if(n){
		if(n-1){
			while(n>1){
			if(!(x-1)){printf("-1");return 0;}
			if(n%x) x--; else {res=res+x*pow(10,t++);n/=x;}
			}
		}else{printf("1");return 0;}
	}else {printf("10");return 0;}
	long long kq=res%10;
	printf("%lld",res);
}
