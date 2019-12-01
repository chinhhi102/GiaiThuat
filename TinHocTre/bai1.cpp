#include<bits/stdc++.h>
using namespace std;
int main(){
	int a[3];
	freopen("D:\\baiTapLapTrinh\\TinHocTre\\bai1\\key1.inp", "w", stdout);
	for(int i=0;i<3;i++){
		cin>>a[i];
		cout<<a[i]<<" ";
	}
	freopen("D:\\baiTapLapTrinh\\TinHocTre\\bai1\\key1.out", "w", stdout);
	sort(a,a+3);
	cout<<a[0]*(a[1]+a[2]);
	return 0;
}
