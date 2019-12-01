#include<bits/stdc++.h>
using namespace std;
#define N 1000001
int f[N]={0},n,id=2;
int main(){
    for(int i=2;i<N;i++) if(!f[i])
	for(int j=i*2;j<N;j+=i)f[j]=1;
    scanf("%d",&n);
    while(f[n]){
        while(!(n%id)&&f[n]) printf("%d*",id,n/=id); id++;
        while(f[id]) id++;
    }
    printf("%d",n);
}
