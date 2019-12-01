#include <cstdio>
int main(){
    int x,y;
    scanf("%d%d",&x,&y);
    printf("%s\n",((x-y+1)%2==0&&y>0&&x>=(y-1)&&!(x>0&&y==1)?"Yes":"No"));
    return 0;
}
