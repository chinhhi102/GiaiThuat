#include<bits/stdc++.h>
#define N 10000000
int n,a[N]={},id(2);
using namespace std;
int main(){ 
	ios::sync_with_stdio(0),cin.tie(0);
	for(int i=2;i<=sqrt(N);i++)if(!a[i])for(int j=i*i;j<N;j+=i)a[j]=1;
	scanf("%d",&n);
	for(;id<N&&n;id++)if(!a[id])n--;
	printf("%d",id-1);
}
