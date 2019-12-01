#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	n=30;	
	int f[31]={};
	f[1]=1;
	f[2]=1;
	for(int i=3;i<31;i++)
		f[i]=f[i-1]+f[i-2];
	cout<<f[n];
	freopen("D:\\baiTapLapTrinh\\TinHocTre\\bai3\\key30.inp", "w", stdout);
	cout<<n;
	freopen("D:\\baiTapLapTrinh\\TinHocTre\\bai3\\key30.out", "w", stdout);
	cout<<f[n];
	return 0;
}
