#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,tong(0);
	scanf("%d",&n);
	tong=n;
	while(tong/10>0)
	{
	    tong -= 7;
	    n += 3;
	}
	printf("%d",n);
	return 0;
}
