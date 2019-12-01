#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,a[100],to;
    scanf("%d",&n);
    for(int i=0;i<n;i++)scanf("%d",&a[i]);
    sort(a,a+n);
    to=min(n-1,a[n-1]);
    for(int i=1;i<=to;i++) to=min(to,i+a[n-i-1]);
    printf("%d",to+1);
}
