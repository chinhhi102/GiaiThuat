#include<bits/stdc++.h>
using namespace std;
int n,a[21],t=0,s,k;
void in(){
	s=0;
	for (k=1;k<=n;k++){(!a[k])?s++:s--;if(s<0)break;}
	if (!s){t++;for(int l=1;l<=n;l++)printf(a[l]?")":"(");printf("\n");}
}
void kt(int j){
	for (int i=0;i<=1;i++){
		a[j]=i;
		(j==n)?in():kt(j+1);
	}
}
int main(){	
	scanf("%d",&n);
	kt(1);
	printf("%d",t);
}
