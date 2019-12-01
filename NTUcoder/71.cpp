#include<bits/stdc++.h>
using namespace std;
int sum(long long t){
	int m=t%10,x=t;
	while(t/=10){
		m+=t%10;
	}
	return t = x%m?0:1;
}
int main(){
	int t(0);
	scanf("%lld",&t);printf("%d",sum(t));
    return 0;
}


