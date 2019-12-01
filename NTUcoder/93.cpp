#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m,res(0);
    scanf("%d%d",&n,&m);int a[n],b[m];
    for(int i=0;i<n;i++)scanf("%d",&a[i]);
    for(int i=0;i<m;i++)scanf("%d",&b[i]);
    sort(a,a+n);
    sort(b,b+m);
    for(int i=0,j=0;i<n&&j<m;){
    	if(a[i]>b[j])res++,i++,j++;else i++;
	}
	printf("%d",res);
}
