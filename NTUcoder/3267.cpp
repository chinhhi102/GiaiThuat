#include<bits/stdc++.h>
using namespace std;
int main(){
    long long t,u,v,r,l;
    scanf("%d",&t);
    while(t--){
    	scanf("%lld%lld",&u,&v);
        l=sqrtl(u),r=sqrtl(v);
        if(l*l==u)l--;
        printf("%lld\n",r-l);
    }
}
