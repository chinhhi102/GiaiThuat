#include<bits/stdc++.h>
using namespace std;
int main(){
	int a,b,v;
	scanf("%d%d%d",&a,&b,&v);
	printf("%d",a>=v?1:((v-b)%(a-b))?((v-b)/(a-b)+1):((v-b)/(a-b)));
}
