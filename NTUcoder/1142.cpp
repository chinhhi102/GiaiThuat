#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	scanf("%d",&n);
	int a[n],j=0,t;
	for (int i=0;i<n;i++)scanf("%d",&a[i]);
	for (int i=0;i<n-1;i++)if (a[i]<=a[n-1])swap(a[i],a[j]),j++;
	for (int i=0;i<n-1;i++)(i==j)?printf("[%d] ",a[n-1]):printf("%d ",a[i]);
	(j==n-1)?printf("[%d]",a[j]):printf("%d",a[j]);
}
