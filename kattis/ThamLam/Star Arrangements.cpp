#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	scanf("%d",&n);
	printf("%d:\n",n);
	int x=2,y=1;
	while(n/y>=2){
		if((n-x)%(x+y)==0||(x==y&&n%x==0)||n%(x+y)==0)printf("%d,%d\n",x,y);
		x!=y?y++:x++;
	}
}
