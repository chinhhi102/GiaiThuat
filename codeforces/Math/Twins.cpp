#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	scanf("%d",&n);
	int a[n],sum(0),res(0),t;
	for(int i=0;i<n;i++){scanf("%d",&a[i]);sum+=a[i];}
	sort(a,a+n);
	for(int i=n-1;i>=0&&t<=sum/2;i--){t+=a[i];res++;}
	printf("%d",res);
}
