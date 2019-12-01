#include <bits/stdc++.h>
using namespace std;
int main()
{
	long long a,b;
	scanf("%lld%lld",&a,&b);
	while (a&&b) a>b?a%=b:b%=a;
	printf("%lld",a+b);
	return 0;
}
