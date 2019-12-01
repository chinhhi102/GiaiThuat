#include<bits/stdc++.h>
using namespace std;
const long long INF=1000000000000000;
int a[20];
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		int x,p,y;
		scanf("%d%d%d",&x,&p,&y);
		int cur=0;
		for(int i=2;i*i<=p;i++) if(p%i==0){
			a[cur++]=i;
			while(p%i==0) p/=i;
		}
		if(p>1) a[cur++]=p;
		int cnt1=0;
		for(int i=(1<<cur)-1;i>=0;i--){
			int now=1,flag=1;
			for(int j=0;j<cur;j++) if(i&(1<<j)) now*=a[j],flag=-flag;
			cnt1+=(x/now)*flag;
		}
		long long l=x,r=INF;
		while(l<r){
			long long m=(l+r)/2;
			long long cnt=0;
			for(int i=(1<<cur)-1;i>=0;i--){
				int now=1,flag=1;
				for(int j=0;j<cur;j++) if(i&(1<<j)) now*=a[j],flag=-flag;
				cnt+=(m/now)*flag;
			}
			if(cnt-cnt1<y) l=m+1;
			else r=m;
		}
		printf("%lld\n",l);
	}
	return 0;
}
