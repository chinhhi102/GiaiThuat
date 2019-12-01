#include<bits/stdc++.h>
using namespace std;
int sq(int a,int b){
    static int m(0);
    return ++m = (a>b)?m-2:sq(2*a,b);
}
int main(){
	int n,m,h(0);
	scanf("%d%d",&n,&m);
	{
	   printf("%d",sq(n,m));
	}
	
	
	return 0;
}
