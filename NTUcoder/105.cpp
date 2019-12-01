#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,a[100],b[101],res=0;
    scanf("%d",&n);
    for(int i=1;i<n;i++)scanf("%d",&a[i]);
    for(int i=1;i<=n;i++){
        scanf("%d",&b[i]);
        if(b[i]>b[i-1])b[i]=b[i-1];
    }
    for(int i=1;i<n;i++)res+=b[i]*a[i];
	printf("%d",res);
}
