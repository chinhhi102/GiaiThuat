#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,x,res(1),t,temp(0);
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&x);
		if(x==t)res=max(++temp,res);else temp=1;
		t=x;
	}
	printf("%d",n-res);
}
