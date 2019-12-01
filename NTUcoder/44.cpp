#include<bits/stdc++.h>
using namespace std;
int main(){
	long long n;
	scanf("%lld",&n);
	if(n==1){
	    printf("NO");
	    return 0;
	}
	{
	    for (int i = 2; i <= sqrt(n); i++) {
	        if(n%i==0&&n>2){
	            printf("NO");
	            return 0;
	        } 
	    }
	    printf("YES");
	}
	return 0;
}
