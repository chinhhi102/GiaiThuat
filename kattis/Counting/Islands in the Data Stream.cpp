#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
	int n,num;
	scanf("%d",&n);
	int a[12];
	for(int test=0;test<n;test++){
		scanf("%d",&num);
		int sum=0;
		for(int i=0;i<12;i++)scanf("%d",&a[i]);
		for (int daoMax=1;daoMax<11;daoMax++){
			for (int viTri=1;viTri<12-daoMax;viTri++){
				bool island=1;
				for(int tam=0;tam<daoMax;tam++){
					if(a[viTri+tam]<=a[viTri-1] || a[viTri+tam]<=a[viTri+daoMax]){
						island=0;
						break;
		 			}
	    		}
				if(island)sum++;
   			}
		}
	printf("%d %d\n",test+1,sum);
	}
}
