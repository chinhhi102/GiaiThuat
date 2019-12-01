#include<bits/stdc++.h>
using namespace std;
int main(){
	int a,b;
	scanf("%d%d",&a,&b);
	if(a>b){
		int temp=a;
		a=b;
		b=temp;
	}
	int i=a+1;
	do printf("%d\n",i),i++;while(i<b+2);
}
