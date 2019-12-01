#include<bits/stdc++.h>
#define for(i,a,b) for(int i=a;i<=b;i++)
int a[1000][1000]={},n,sx,sy,dx,dy,flag(0);
void res(int i,int j){
	if(!flag){
	a[i][j]=1;
	if(i==dx&&j==dy){flag=1;return;}
	if (i+1<=n && !a[i+1][j]) res(i+1,j);
	if (i-1>=1 && !a[i-1][j]) res(i-1,j);
	if (j+1<=n && !a[i][j+1]) res(i,j+1);
	if (j-1>=1 && !a[i][j-1]) res(i,j-1);
	}
}
using namespace std;
int main(){
	scanf("%d%d%d%d%d",&n,&sx,&sy,&dx,&dy);
	for(i,1,n)for(j,1,n)scanf("%d",&a[i][j]);
	res(sx,sy);
	printf(flag?"YES":"NO");
}
