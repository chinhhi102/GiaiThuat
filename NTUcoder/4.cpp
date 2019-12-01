#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,m;
	scanf("%d%d",&n,&m);int a[n+1];
	for(int i=0;i<n;i++)scanf("%d",&a[i]);
	sort(a,a+n);a[n]=2;
	for(int i=n;i>=0;m-=a[i]-1,i--)if(m<a[i]){
		printf("%d",n-i);
		return 0;
	}printf("-1");
}
