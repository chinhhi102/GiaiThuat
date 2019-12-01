#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	scanf("%d",&n);
	{
	    int m,L1(0),L2(0),L;
	    while(n--){
	       scanf("%d",&m);
	       L+=m;
	       if(m-100)L2++;
	       else L1++;
	   }
	   (L2%2)?((L/2)%200)?printf("NO"):printf("YES"):((L%200)?printf("NO"):printf("YES"));
	}
	return 0;
}
