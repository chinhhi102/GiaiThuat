#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,a[30000],res=-1;
    scanf("%d",&n);
    for(int i=0;i<n;i++)scanf("%d",&a[i]);
    for(int i=2;i<n;i++){
        int temp=2;
        while(a[i]==a[i-1]+a[i-2])temp++,i++;
        if(temp>2)res=max(res,temp);
    }
    printf("%d",res);
}
