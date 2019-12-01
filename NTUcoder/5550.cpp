#include <bits/stdc++.h>
using namespace std;
#define for(i,a,b) for(int i=a;i<=b;i++)
int main(){
	int a[10]={6,2,5,5,4,5,6,3,7,6};
	int n,i,j,z,t;
	scanf("%d",&n);
	for(i,0,1)for(j,0,9)for(z,0,6)for(t,0,9)if(a[i]+a[j]+a[z]+a[t]==n){printf("%d%d:%d%d",i,j,z,t);return 0;}
	printf("Impossible");
}
