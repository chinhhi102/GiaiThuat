#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,m;
	scanf("%d",&n);
	int a[n+1];a[0]=0;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		a[i]+=a[i-1];
	}
	scanf("%d",&m);
	int b[m+1];b[0]=0;
	for(int i=1;i<=m;i++)scanf("%d",&b[i]);
	for(int i=1;i<=m;i++){
		int l=0,r=n;
		while(1){
			int mid=(l+r)/2;
			if(b[i]<=a[mid]&&b[i]>a[mid-1]){
				printf("%d ",mid);
				break;
			}else if(b[i]<=a[mid-1]&&b[i]>a[mid-2]){
				printf("%d ",mid-1);
				break;
			}else (a[mid-1]>b[i])?r=mid-1:l=mid+1;
		}
	}
	return 0;
}
