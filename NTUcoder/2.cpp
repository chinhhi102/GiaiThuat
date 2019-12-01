#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	scanf("%d",&n);
	{
	    int l(7),r(0);
	    (n/7%2==1)?(r=7-(l=n%7)):(l=7-(r=n%7));
	    printf("%d %d",l,r);
	    
	}
	return 0;
}
