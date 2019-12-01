#include<bits/stdc++.h>
using namespace std;
int main(){
    int a,b,c;
    while(1){
        scanf("%d%d%d",&a,&b,&c);
        if(!a&&!b&&!c)break;
        (b-a==c-b)?printf("AP %d\n",c*2-b):printf("GP %d\n",c*(b/a));
    }
}
