#include<bits/stdc++.h>
using namespace std;
int main(){
    int d,t,n,m[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
    scanf("%d%d%d",&d,&t,&n);
    m[2]+=(n%100&&n%4==0||n%400==0);
    d==m[t]?printf("1 %d %d",t+1-12*(t==12),n+(t==12)):printf("%d %d %d",d+1,t,n);
}
