#include<bits/stdc++.h>
using namespace std;
int main(){	
	int n,m(0);
 	scanf("%d",&n);int a[n],t=n-1,res=1e9;
 	for(int i=0;i<n;i++) scanf("%d",&a[i]);
 	sort(a,a+n);
 	for(int i=1;i<n;i++) res=min(res,a[i]-a[i-1]);
	printf("%d",res);
}
