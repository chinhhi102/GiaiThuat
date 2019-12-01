#include<bits/stdc++.h>
using namespace std;
int main(){
	int count=0,n;
	scanf("%d",&n);
	for(int c=1;c<=n;c++){
		for(int b=1;b<=c;b++){
			int k=b^c;
			if(k<=b&&k>c-b)
				count++;
			printf("%d %d\n",k,count);
		}
	}printf("\n");
	printf("%d",count);
}
