#include<bits/stdc++.h>
using namespace std;
int n,m,con=0,a;
map<int,int>M;
int main(){
    scanf("%d%d",&n,&m);
    while(n--){
        scanf("%d",&a);
        if(M[a-m]){
        	printf("%d %d",a-m,a);
        	return 0;
        }
        M[a]=1;
    }
    printf("-1");
}
