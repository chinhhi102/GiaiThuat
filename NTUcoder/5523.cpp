#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,a[5]={0},x;
    scanf("%d",&n);
    while(n--)scanf("%d",&x),a[x]++;
    (a[1]>a[3])?a[1]-=a[3]:a[1]=0;
    if(a[2]%2){
        a[2]=a[2]/2+1;
        a[1]=(a[1]>2)?a[1]-2:0;
    }
    else a[2]=a[2]/2;
    a[1]=a[1]/4+(a[1]%4>0);
    printf("%d",a[1]+a[2]+a[3]+a[4]);
}
