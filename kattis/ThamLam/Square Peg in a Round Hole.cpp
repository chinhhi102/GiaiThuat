#include<bits/stdc++.h>
using namespace std;
#define for(i,a,b) for(int i=a;i<b;i++)
int main(){
	int n,m,k,res(0),tm;
	scanf("%d%d%d",&n,&m,&k);
	int a[102]={},b[204]={},c;
	for(i,0,n)scanf("%d",&a[i]);
	for(i,0,m)scanf("%d",&b[i]);
	for(i,m,m+k){
		scanf("%d",&c);
		b[i]=c*sqrt(2)/2.0;
	}
	sort(a,a+n);sort(b,b+m+k);
	for(i,0,n){
		if(b[res]<a[i]&&res<m+k)res++;
		tm=i;
	}
	res+=tm<(n-1)?n-1-tm:0;
	printf("%d",res);
}
