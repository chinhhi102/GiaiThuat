#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,k,res(0),l(0);
    scanf("%d%d",&n,&k);int a[n];
    for(int i=0;i<n;i++) scanf("%d",&a[i]);
    sort(a,a+n);
    for(int i=1;i<n;i++){
        int r=i;
        while(l<=r){
            int mid=(l+r)/2;
            if(a[i]-a[mid]==k){res++;break;}
            (a[i]-a[mid]>k)?l=mid+1:r=mid-1;
        }
    }
    printf("%d",res);
    return 0;
}
