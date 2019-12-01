#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    scanf("%d",&n);m=n/2;
    for(int i=0;i<n;i++){
    	for(int j=0;j<abs(m);j++)printf("*");
    	for(int j=0;j<n-abs(m)*2;j++)printf("D");
    	for(int j=0;j<abs(m);j++)printf("*");
    	printf("\n");
    	m--;
	}
}
