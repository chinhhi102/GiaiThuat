#include<bits/stdc++.h>
using namespace std;
int Sub(int x){
    int m(0);
    for (int i = 1; i <= x/2; i++) {
        if(!(x%i))m+=i;
    }
    return m;
}
int main(){
	int n,m,h(0);
	scanf("%d%d",&n,&m);
	{
	    if(!(Sub(m)-n)&&!(m-Sub(n))) printf("YES");
	    else printf("NO");
	}
	
	
	return 0;
}
