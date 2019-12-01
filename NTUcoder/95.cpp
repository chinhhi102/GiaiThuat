#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	scanf("%d",&n);
	{
	    long long d(1);
	    for (int i = 1; i <= n; i++) {
	        d*=i;
	    }
	    printf("%lld",d);
	}
}
