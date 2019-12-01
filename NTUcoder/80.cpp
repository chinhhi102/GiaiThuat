#include<bits/stdc++.h>
using namespace std;
int main(){
	int m,n;
	scanf("%d%d",&n,&m);
	{
	while(n!=m){
	    (n>m)?n-=m:m-=n;
	}
	printf("%d",m);
	}
}
