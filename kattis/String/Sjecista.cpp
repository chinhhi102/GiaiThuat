#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	scanf("%d",&n);
	printf("%lld",n-3?n*(n-1)*(n-2)*(n-3)/24:0);
}
