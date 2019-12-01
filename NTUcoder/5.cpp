#include<bits/stdc++.h>
using namespace std;
#define for(i,a,b) for(int i=a;i<=b;i++)
int main(){
	int xc,xd,tc,td,res=0;
	scanf("%d%d%d%d",&xd,&xc,&td,&tc);
	for(i,1,8)for(j,1,8)(j==xc)?res++:(i==xd)?res++:(i+j==td+tc)?res++:(i-j==td-tc)?res++:0;
	printf("%d",res);
}
