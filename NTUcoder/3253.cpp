#include<stdio.h>
int main(){
    int x,y;
    char a[5]={'A','B','C','D','E'};
    scanf("%d%d",&y,&x);
    if(y>=5)printf("%d\n%c",x%2+y-3,a[x/2]);
    else if(x%2==0&&y==4)printf("%d\n%c",1,a[x/2]);
    else printf("-1");
}
