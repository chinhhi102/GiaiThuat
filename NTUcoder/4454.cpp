#include<bits/stdc++.h>
#define for(i,a,b) for(int i=a;i<b;i++)
using namespace std;
int main(){
	long long n,j(0),f(1);
	scanf("%d",&n);int a[n];
	for(i,0,n)scanf("%d",&a[i]);
	sort(a,a+n);
	for(i,0,n)(a[i]>j*j&&f)?printf("%lld",j*j,f=0):(a[i]==j*j)?j++:i;
	if(f)printf("%lld",j*j);
}
