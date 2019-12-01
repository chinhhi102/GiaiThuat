#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	int t,k,x,l,r;
	int ans[1010];
	scanf("%d",&t);
	while (t--){
		int t=0;
		scanf("%d",&n);
		for (int i=1;i<=n;i++){
			scanf("%d%d",&l,&r);
			if (t<l) t=l,ans[i]=t,t++;
			else if (r<t) ans[i]=0;
			else ans[i]=t,t++;
		}
		for (int i=1;i<=n;i++)
			printf("%d ",ans[i]);
		printf("\n");
	}
}
