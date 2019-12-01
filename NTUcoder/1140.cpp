#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,x,kt,min;
	scanf("%d",&n);
	int a[n],b[n];
	for (int i = 0; i < n; i++)scanf("%d",&a[i]);
	for (int i = 0; i < n-1; i++){
		min = i;
		for (int j=i+1;j<n;j++)if(a[min]>a[j])min=j;
		swap(a[i],a[min]);
		for (int k = 0; k < n; k++)	(k==min || k==i)?printf("[%d] ",a[k]):printf("%d ",a[k]);printf("\n");
	}
}
