#include<bits/stdc++.h>
using namespace std;
int main(){
    int x[3],y[3];
    for(int i=0;i<3;i++)scanf("%d%d",&y[i],&x[i]);
    (x[2]==0||x[2]==8||x[2]==0||x[2]==9||x[2]!=x[1]&&y[2]!=y[1])?printf("-1"):(x[1]==x[2])?printf("%d",(y[2]-y[1])*(y[0]-y[2])>0?2-(x[0]==x[2]):4-(x[0]!=x[2])):printf("%d",((x[2]-x[1])*(x[0]-x[2])>0)?2-(y[0]==y[2]):4-(y[0]!=y[2]));
}
