#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	srand(time(0));
	n=100;
	cout<<n;
	cout<<endl;
	cout<<11000+(n>29?28*12000:(n-1)*12000)+(n>29?(n-29)*10000:0)<<endl;
//	for(n=0;n<=100;n++)
	freopen("D:\\baiTapLapTrinh\\TinHocTre\\bai2\\key29.inp", "w", stdout);
	cout<<n;
	freopen("D:\\baiTapLapTrinh\\TinHocTre\\bai2\\key29.out", "w", stdout);
	cout<<11000+(n>29?28*12000:(n-1)*12000)+(n>29?(n-29)*10000:0)<<endl;
	return 0;
}
