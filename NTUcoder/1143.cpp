#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,i=1,a[21],b[21],j=1,m;
    scanf("%d%d",&n,&m);
    for (int i=1; i<=n; i++) scanf("%d",&a[i]);
    for (int i=1; i<=m; i++) scanf("%d",&b[i]);
    while (i<=n&&j<=m)(a[i]<b[j])?printf("b%d ",i++):printf("c%d ",j++);
    while (i<=n)printf("b%d ",i++);
    while (j<=m)printf("c%d ",j++);
}
