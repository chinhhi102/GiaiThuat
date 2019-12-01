#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,group[5]={},x,res(0);
	scanf("%d",&n);
	while(n--){
		scanf("%d",&x);
		group[x]++;
	}
	res=group[4];
	res+=group[2]/2;
	group[2]=group[2]%2;
	if(group[2])group[1]-=2,res++;
	if(group[3]>group[1])res+=group[3];else{
		res+=group[3];
		group[1]-=group[3];
		if(group[1]>0)
		res+=group[1]/4+1*(group[1]%4>0);
	}
	printf("%d",res);
}
