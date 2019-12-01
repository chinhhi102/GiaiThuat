#include<bits/stdc++.h>
using namespace std;
int main(){
    int t,a[3];
    scanf("%d",&t);
    while(t--){
        for(int i=0;i<3;i++)scanf("%d",&a[i]);
        sort(a,a+3);
        printf("%d\n",a[1]*2+(a[2]>a[1]));
    }
}
