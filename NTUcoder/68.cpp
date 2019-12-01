#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,x;
    long long f[2]={};
    scanf("%d",&n);
    while(n--)scanf("%d",&x),f[x%2]++;
    printf("%lld",(f[1]%2)?f[1]*f[0]:f[0]*(f[0]-1)/2+f[1]*(f[1]-1)/2);
}
