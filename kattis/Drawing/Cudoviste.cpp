#include<bits/stdc++.h>
using namespace std;
int main(){
	int R,C,res[5]={};
	scanf("%d%d",&R,&C);
	char Map[R][C];
	cin.ignore();
	for(int i=0;i<R;i++) gets(Map[i]);
	for(int i=0;i<R-1;i++)for(int j=0;j<C-1;j++){
		int f=1,count=0;
		for(int k=i;k<i+2;k++)for(int l=j;l<j+2;l++){
			if(Map[k][l]=='#')f=0;
			if(Map[k][l]=='X')count++;
		}
		if(f)res[count]++;
	}
	for(int i=0;i<5;i++)printf("%d\n",res[i]);
}
