#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m,k;
    scanf("%d%d%d",&n,&m,&k);
    k-=n%2;n-=n%2;
    if(n>2*m)k-=n-2*m;else k-=m-n/2,m=n/2;
    printf("%d",k>0?m-k/3-(k%3>0):m);
}
