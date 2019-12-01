#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,m,old(0),res(0),a;
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++){
		scanf("%d",&a);
		res+=min(m,a+old);
		old=(a+old>m)?(old>m)?a:a+old-m:0;
	}printf("%d",res+min(m,old));
}
