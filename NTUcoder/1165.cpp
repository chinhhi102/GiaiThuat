#include<bits/stdc++.h>
#define mod 1000007
long long r=1,p=1,n,tmp;
using namespace std;
int main(){
    scanf("%lld",&n);n=n>2?n-=2:0;
    while(n--)tmp=(r+p)%mod,r=p,p=tmp;printf("%lld",p);
}
