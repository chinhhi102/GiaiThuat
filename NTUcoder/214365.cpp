#include<bits/stdc++.h>
using namespace std;
int main()
{
	int a,b[10]={1,2,3,4,5,6,5,8,9,10};
	scanf("%d",&a);
	for(int i=0;i<10;i++)
	if(a==b[i]){
		printf("phan tu x co trong mang ");
		return 0;
	}
	printf("phan tu x ko co trong mang");
	return 0;
}
