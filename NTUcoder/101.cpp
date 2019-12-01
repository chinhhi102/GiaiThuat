#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	scanf("%d",&n);
	int m = n;
	while(n--){
		int k = m;
		while(k--){
			n%2?((k%2)?printf("W"):printf("B")):((k%2)?printf("B"):printf("W"));
		}
		printf("\n");
	}
	return 0;
}
