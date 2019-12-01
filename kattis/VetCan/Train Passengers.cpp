#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,c,pas(0),ra,vao,doi,res(1);
	scanf("%d%d",&c,&n);
	for(int i=0;i<n;i++){
		scanf("%d%d%d",&ra,&vao,&doi);
		pas-=ra;
		if(pas<0){
			res=0;break;
		}
		pas+=vao;
		if(pas>c){
			res=0;break;
		}else if(pas<c&&doi!=0){
			res=0;break;
		}
	}
	if(pas>0)res=0;
	printf(res?"possible":"impossible");
}
