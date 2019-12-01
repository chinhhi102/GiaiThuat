#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,k,ma=0;
    long long a[100001];a[0]=0;
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++){
        scanf("%lld",&a[i]);
        a[i]+=a[i-1];
    }
    for(int i=n;i>ma;i--){
        for(int j=0;i-j>ma;j++)
            if((a[i]-a[j])%k==0)ma=i-j;
    }
    printf("%d",ma);
}
