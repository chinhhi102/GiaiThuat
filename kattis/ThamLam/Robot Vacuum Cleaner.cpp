#include<bits/stdc++.h>
using namespace std;
struct data{
	int conh=0,cons=0;
};
int main(){
	int n,sums(0),sumh(0),res(0);
	scanf("%d",&n);
	char text[n][100001];
	data tong[n];
	cin.ignore();
	for(int i=0;i<n;i++){
		gets(text[i]);
		for(int j=0;j<strlen(text[i]);j++){
			if(text[i][j]=='h')sumh++,tong[i].conh++;else sums++,tong[i].cons++;
		}
	}
	printf("%d %d",sumh,sums);
}
