#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,m;
	scanf("%d%d",&n,&m);int a[n+1];
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int i=0;i<m;i++){for(int j=1;j<=n;j++) printf((a[j]>=m-i)?"#":".");printf("\n");}
}
