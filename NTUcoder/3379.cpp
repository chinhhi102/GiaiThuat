#include<bits/stdc++.h>
using namespace std;
int n,k,a[10000],s[10000],d;
void res(int i){
	if(i>k){
		for(int j=1;j<=i-1;j++)printf("%d ",s[j]);
		printf("\n");
	}
 	if(i<=k)for(int j=1;j<=n;j++)if(!a[j]){
		a[j]=1;
		s[i]=j;
		res(i+1);
		a[j]=0;
	}
}
int main(){
	scanf("%d%d",&n,&k);
	res(1);
}
