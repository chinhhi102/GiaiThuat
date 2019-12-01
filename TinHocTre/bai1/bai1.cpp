#include<bits/stdc++.h>
using namespace std;
int main(){
	int a[3];
	srand(time(0));
	for(int i=0;i<3;i++){
		a[i]=rand()%10000;
		cout<<a[i]<<" ";
	}
	cout<<endl;
	sort(a,a+3);
	cout<<a[0]*(a[1]+a[2]);
	freopen("D:\\baiTapLapTrinh\\TinHocTre\\bai1\\key40.inp", "w", stdout);
	for(int i=0;i<3;i++){
//		a[i]=rand()%500;
		cout<<a[i]<<" ";
	}
	freopen("D:\\baiTapLapTrinh\\TinHocTre\\bai1\\key40.out", "w", stdout);
//	sort(a,a+3);
	cout<<a[0]*(a[1]+a[2]);
	return 0;
}
