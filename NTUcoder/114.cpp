#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    int a=pow(n,m),res[m];
    printf("%d\n",a);
    for(int i=0;i<m;i++)res[i]=1;
	for(int k=1;k<=a;k++){
    for(int i=0;i<m;i++)printf("%d",res[i]);printf("\n");
	for(int i=m-1;i>=0;i--){
		if(res[i]<n){
			res[i]++;
			for(int j=i+1;j<m;j++)res[j]=1;
			break;
		}
	}
	}
}
