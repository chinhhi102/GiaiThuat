#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	scanf("%d",&n);
	{
	int i = 1,d=0;
	while(i<=n/2){
		if(n%i++==0) d+=i-1;
	}
	if(d==n)printf("YES");else printf("NO");
	}
}
