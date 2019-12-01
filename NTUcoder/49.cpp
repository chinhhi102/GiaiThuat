#include<bits/stdc++.h>
using namespace std;
int main(){
    int a,b,res(0);
    scanf("%d%d",&a,&b);
    a=a^b;
    while(a)res+=a%2,a/=2;
    printf("%d",res);
}
