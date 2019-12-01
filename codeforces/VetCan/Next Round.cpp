#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,d,a[101],res(0);
	scanf("%d%d",&n,&d);
	for(int i=0;i<n;i++)scanf("%d",&a[i]);
	for(int i=0;i<n;i++)if(a[i]&&a[i]>=a[d-1])res++;
	printf("%d",res);
}
