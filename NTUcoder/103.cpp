#include<bits/stdc++.h>
using namespace std;
bool check(0);
int a[25]={},n;
int main(){
	scanf("%d",&n);
	while(!check){
		for(int i=1;i<=n;i++) printf("%d",a[i]);printf("\n");
		int i = n;
		while(a[i]&&i>0)i--;
		if(!i) check=1; else{
			a[i]=1;
			for(int j = i+1; j<=n; j++) a[j]=0;
		}
	}
}
/************************************/
#include<bits/stdc++.h>
using namespace std;
int a,A[25];
void pri();
void next(int n);
int main(){
	scanf("%d",&a);
	next(1);
}
void pri(){
	for(int i = 0; i<a; i++) printf("%d",A[i]); printf("\n");
}
void next(int n){
	for(int i = 0; i < 2; i++){
		A[n-1]=i;
		n-a?next(n+1):pri();
	}
}
