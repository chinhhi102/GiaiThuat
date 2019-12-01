#include<bits/stdc++.h>
#define for(i,a,b) for(int i=a;i<=b;i++)
int a[1000][1000]={},n,m,sx,sy,dem(0);
void res(int i,int j){
	dem++;
	a[i][j]=1;
	if (i+1<=n && !a[i+1][j]) res(i+1,j);
	if (i-1>=1 && !a[i-1][j]) res(i-1,j);
	if (j+1<=m && !a[i][j+1]) res(i,j+1);
	if (j-1>=1 && !a[i][j-1]) res(i,j-1);
}
using namespace std;
int main(){
	scanf("%d%d%d%d",&n,&m,&sx,&sy);
	for(i,1,n)for(j,1,m)scanf("%d",&a[i][j]);
	res(sx,sy);
	printf("%d",dem);
}
