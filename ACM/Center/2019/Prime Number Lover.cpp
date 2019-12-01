#include<bits/stdc++.h>
using namespace std;
#define MAXN 10000010
bitset<MAXN> isp;
void sieve(){
	isp.set();
	isp[0]=isp[1]=0;
	for(long long i=2;i<MAXN;i++){
		if(isp[i])
			for(long long j=i*i;j<MAXN;j+=i)
				isp[j]=0;
	}
}
int main(){
	sieve();
	int n;
	cin>>n;
	int a[n],count[n+1]={};
	for(int i=0;i<n;i++)
		cin>>a[i];
	count[0]=0;
	for(int i=0;i<n;i++){
		if(isp[a[i]])
			count[i+1]=count[i]+1;
		else
			count[i+1]=count[i];
	}
	int total=0;
	for(int i=1;i<=n;i++){
		for(int j=0;j<i;j++)
			if((count[i]-count[j])*2 >= (i-j))
				total++;
	}
	cout<<total;
}
