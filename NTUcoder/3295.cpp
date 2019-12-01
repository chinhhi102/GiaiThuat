#include<bits/stdc++.h>
using namespace std;
int main(){
	int diem[6];
	for(int i=0;i<6;i++)scanf("%d",&diem[i]);
	if((diem[2]-diem[0])*(diem[4]-diem[2])+(diem[3]-diem[1])*(diem[5]-diem[3])==0)printf("%d %d",diem[4]-diem[2]+diem[0],diem[5]-diem[3]+diem[1]);
	else if((diem[0]-diem[2])*(diem[4]-diem[0])+(diem[1]-diem[3])*(diem[5]-diem[1])==0)printf("%d %d",diem[4]-diem[0]+diem[2],diem[5]-diem[1]+diem[3]);
	else printf("%d %d",diem[0]-diem[4]+diem[2],diem[1]-diem[5]+diem[3]);
}
