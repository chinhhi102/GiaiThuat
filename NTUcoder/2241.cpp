#include<bits/stdc++.h>
#define for(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
int main(){
	int n,res(-1),m,k;
	scanf("%d%d%d",&n,&m,&k);int a[n*m];
	for(i,1,n)for(j,1,m)a[++res]=i*j;
	sort(a,a+n*m);
	printf("%d",a[k-1]);
}
