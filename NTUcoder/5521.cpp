#include<bits/stdc++.h>
using namespace std;
int main(){
	long long n,i(1),dk(1);
	scanf("%lld",&n);
	if(!(n-1)){printf("YES");return 0;}
	while(dk<n&&i++){
		dk+=i;
	}
    printf(dk-n?"NO":"YES");
}
