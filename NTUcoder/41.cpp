#include<bits/stdc++.h>
using namespace std;
bool test(int x){
	int a=x%10,b,t=x;	
	while(x/=10){
		b=x%10;
		a=a*10+b;
	}
	return t = (t-a)?0:1;
}
int main(){
	int t,n;
	scanf("%d",&n);
	while(n--){
		scanf("%d",&t);
		test(t)?printf("%d ",t):printf("");
	}
    return 0;
}
