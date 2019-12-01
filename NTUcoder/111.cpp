#include<bits/stdc++.h>
using namespace std;
int n,x[10];
bool a[10];
int perline(){
	for(int i=1;i<=n+1;i++)
		printf(!(i-n-1)?"\n":"%d",x[i]);
}
int incurred(int i){
	for(int j = 1; j <= n ; j++)
		if(a[j])
			continue;
		else{
			x[i]=j;
			if(!(i-n))
				perline();
			else{
				a[j]=1;
				incurred(i+1);
				a[j]=0;
			}
		}
}
int main(){
    int res(1);
    scanf("%d",&n);
    for(int i=1;i<=n;i++)res*=i;printf("%d\n",res);
	incurred(1);
}
