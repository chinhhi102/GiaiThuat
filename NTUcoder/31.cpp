#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	scanf("%d",&n);int a[n][n]={},i(0);
	for(int i=0;i<n;i++) a[i][0]=a[i][i]=1;
	while(n--){
		printf("%d ",a[i][0]);if(!i){printf("\n");i++;continue;}
		for(int j=1;j<i;j++) printf("%d ",a[i][j]=a[i-1][j-1]+a[i-1][j]);
		printf("%d\n",a[i][i]);i++;
	}
}
