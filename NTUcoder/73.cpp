#include<bits/stdc++.h>
using namespace std;
int main(){	
	int n,t,m=0,lim=10e9;
 	scanf("%d",&n);
 	while(n--){
 		scanf("%d",&t);
 		m=max(m,t-lim);
 		lim=min(t,lim);
	}
	printf("%d",m);
}
