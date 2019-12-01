#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,res(0),t(0);
	scanf("%d",&n);int a[n];
	for(int i=0;i<n;i++) scanf("%d",&a[i]);
	sort(a,a+n);
	for(int i=n-1,j=1;i>=0;i--,j++) res=res-j>a[i]?res:res+(a[i]-(res-j));
	printf("%d",res+1);
}
