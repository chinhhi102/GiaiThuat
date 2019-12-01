#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,m;
    scanf("%d%d",&n,&m);
    printf("%d",(int)(pow(n,m%4?m%4:4))%10);
}
