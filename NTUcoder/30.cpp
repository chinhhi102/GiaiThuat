#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	scanf("%d",&n);
	printf("1 1 ");
	{
	    long long r(1),p(1);
	    while((n--)-2){
	        p+=r;
	        r=p-r;
	        printf("%lld ",p);
	    }
	}
	return 0;
}
