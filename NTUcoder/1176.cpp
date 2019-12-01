#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,res=0;
    scanf("%d",&n);int a[n];
    for(int i=0;i<n;i++)scanf("%d",&a[i]);
    sort(a,a+n);
    for(int i=n-1,j=0;i>=0&&a[i]-j>0;i--,j++) res+=a[i]-j;
    printf("%d",res);
}
