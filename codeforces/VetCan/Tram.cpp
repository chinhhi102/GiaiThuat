#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,pas(0),res(0);
	scanf("%d",&n);
	while(n--){
		int in,out;
		scanf("%d%d",&in,&out);
		pas-=in;
		pas+=out;
		res=max(res,pas);
	}
	printf("%d",res);
}
