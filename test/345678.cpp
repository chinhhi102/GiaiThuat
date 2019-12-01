#include<bits/stdc++.h>
using namespace std;
int main(){
	int a=45;
	int **p;
	p = new int*[10];
	for(int i=0;i<10;i++)
		*(p+i) = new int[10];
	
	for(int i=0;i<10;i++){
		for(int j=0;j<10;j++){
			printf("%d:%d\t",p[i]+j,sizeof(p[i][j]));
		}
		printf("\n");
	}
	
	for(int i=0;i<10;i++)
		delete p[i];
}
