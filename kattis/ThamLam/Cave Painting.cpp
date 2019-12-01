#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,k;
	scanf("%d%d",&n,&k);
	if(k==1){printf("%s","No");return 0;}
		else if(k==2){printf("%s","Yes");return 0;}
			else for(int i=2;i<=sqrt(max(n,k));i++){
				if((n%i)==0||(k%i)==0){printf("%s","No");return 0;}
				}
	printf("%s","Yes");
}
