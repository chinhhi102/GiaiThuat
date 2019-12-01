#include<bits/stdc++.h>
using namespace std;
int main(){
    int x1,x2,y1,y2;
    scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
    ((x1!=x2&&y1!=y2&&abs(x1-x2)==abs(y1-y2)))?printf("%d %d %d %d",x1,y2,x2,y1):(x1==x2||y1==y2)?printf("%d %d %d %d",x1+y1-y2,y1+x1-x2,x2+y1-y2,y2+x1-x2):printf("-1");
}
