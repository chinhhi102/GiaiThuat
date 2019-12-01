#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,a[3],res(0);
	scanf("%d",&n);
	while(n--){
		int temp(0);
		scanf("%d%d%d",&a[0],&a[1],&a[2]);
		for(int i=0;i<3;i++)if(a[i])temp++;
		if(temp>1)res++;
	}
	printf("%d",res);
}
