#include<bits/stdc++.h>
using namespace std;
struct data{int toaDo,soL;};
bool dk(data a,data b){return (a.toaDo>b.toaDo);}
int main(){
	int n,k,res(0),x,y,d(0),a(0),mod(0);
	scanf("%d%d",&n,&k);
	data cal[2][n+2];
	for(int i=0;i<n;i++){
		scanf("%d%d",&x,&y);
		if(x<0){
			cal[0][a].toaDo=abs(x);
			cal[0][a].soL=y;
			a++;
		}else{
			cal[1][d].toaDo=x;
			cal[1][d].soL=y;
			d++;
		}
	}
	sort(cal[0],cal[0]+a,dk);sort(cal[1],cal[1]+d,dk);
	for(int i=0;i<2;i++){
		for(int j=0;j<a;j++){
			res+=((cal[i][j].soL/k+(cal[i][j].soL%k!=0))*2*cal[i][j].toaDo);
			int tmp=cal[i][j].soL%k?k-cal[i][j].soL%k:0,id=j+1;
			while(tmp>0&&id<a){
				int sub=min(tmp,cal[i][id].soL);
				cal[i][id].soL-=sub;
				tmp-=sub;
				id++;
			}
		}
		a=d;
	}
	printf("%d",res);
}
