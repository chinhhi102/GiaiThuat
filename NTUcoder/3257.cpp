#include<bits/stdc++.h>
using namespace std;
#define N 100001
bool prime(int n){
    if(n==1)return 0;
    int lim=sqrt(n);
    for(int i=2;i<=lim;i++)
    if(n%i==0)return 0;
    return 1;
}
int main(){
    int t,n,f[N];
    for(int i=1;i<N;i++)f[i]=i;
    for(int i=2;i<N;i++)if(f[i]==i)for(int j=i;j<N;j+=i)f[j]-=f[j]/i;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        printf(prime(f[n])?"TRUE\n":"FALSE\n");
    }
}
