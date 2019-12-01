#include<bits/stdc++.h>
using namespace std;
int main(){
	int f[7]={},n,res[7]={},p[7]={},b=0,t[7]={},k=0;
	scanf("%d",&n);
	for(int i=n;i>=0;i--)scanf("%d",&f[i]);p[0]=f[0];p[0]=res[0]=f[0];
	for(int i=1;i<=n;i++)for(int j=0;j<=n;j++)p[i]+=f[j]*pow(i,j);
	for(int i=1;i<=n;i++){
		t[i]=(p[i]-p[i-1]);
		k=t[i-1]*(i-1)-k;
		res[i]=t[i]-k;
	}
	for(int i=0;i<=n;i++)printf("%d ",res[i]);
}
