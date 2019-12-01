#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	scanf("%d",&n);
	{
	    int tong(0);
	    while(n>0){
	        int t = n%10;
	        tong=tong%10+t;
	        n/=10;
	    }
	    (tong-9)?printf("NO"):printf("YES");
	}
	return 0;
}
