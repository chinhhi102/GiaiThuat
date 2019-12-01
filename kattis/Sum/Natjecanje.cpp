#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,dam,intt,res(0),tmp;
	map<int,int>nguyen;
	scanf("%d%d%d",&n,&dam,&intt);
	int hong[dam];
	for(int i=0;i<dam;i++)scanf("%d",&hong[i]);
	for(int i=0;i<intt;i++){scanf("%d",&tmp);nguyen[tmp]++;}
	sort(hong,hong+dam);
	for(int i=0;i<dam;i++){
		if(nguyen[hong[i]-1]){nguyen[hong[i]-1]=0;res++;continue;}
		if(nguyen[hong[i]+1])nguyen[hong[i]+1]=0,res++;
	}
	printf("%d",dam-res);
}
