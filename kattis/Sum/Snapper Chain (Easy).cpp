#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,ns,k,t;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d%d",&ns,&k);
		t=pow(2,ns);
		(k%t==t-1&&k)?printf("Case #%d: ON\n",i):printf("Case #%d: OFF\n",i);
	}
}
