#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,a[300000];
    scanf("%d",&n);
    for(int i=0;i<n;i++)scanf("%d",&a[i]);
    for(int i=n-1;i>=0;i--)if(a[i]==n)n--;
    printf("%d",n);
}
