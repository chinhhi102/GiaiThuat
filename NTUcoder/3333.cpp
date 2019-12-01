#include<bits/stdc++.h>
#define for(i,a,b) for(int i=a;i<b;i++)
using namespace std;
int main(){
	int n,res(0);
	scanf("%d",&n);int a[n],b[n];
	for(i,0,n) scanf("%d%d",&a[i],&b[i]);
	sort(a,a+n);sort(b,b+n);int j(0);
	for(i,0,n){
		if(b[j]>a[i]){
			res+=b[j]-a[i];
			if(a[i]<b[j-1]&&i>0) res-=b[j-1]-a[i]; j++;
		}
	}printf("%d",res);
}
