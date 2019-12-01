#include<bits/stdc++.h>
using namespace std;
int main(){
    int y,x,tx,ty;
    scanf("%d%d%d%d",&y,&x,&ty,&tx);
    printf((abs(ty-y)%2||abs(tx-x)%2||abs(tx-x+ty-y)%4)?"-1":"%d",max(abs(tx-x),abs(ty-y))/2);
}
