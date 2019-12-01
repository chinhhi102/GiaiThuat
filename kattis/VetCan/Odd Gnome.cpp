#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	scanf("%d",&n);
	while(n--){
		int m;
		scanf("%d",&m);
		int a[m];
		for(int i=0;i<m;i++)scanf("%d",&a[i]);
		for(int i=1;i<m;i++)if(a[i+1]-a[i-1]==1){printf("%d\n",i+1);break;}
	}
}
