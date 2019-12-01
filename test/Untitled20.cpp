#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("D:\\baiTapLapTrinh\\test\\Songuyen.inp","r",stdin);
	freopen("D:\\baiTapLapTrinh\\test\\Nguyento.txt","w",stdout);
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++)
		cin>>a[i];
	for(int i=0;i<n;i++){
		if(a[i]==1)continue;
		if(a[i]==2){
			cout<<a[i]<<" ";
			continue;
		}
		bool f=1;
		for(int j=2;j<=sqrt(a[i]);j++){
			if(a[i]%j==0){
				f=0;
				break;
			}
		}
		if(f)cout<<a[i]<<" ";
	}
	freopen("D:\\baiTapLapTrinh\\test\\Chinhphuong.txt","w",stdout);
	for(int i=0;i<n;i++){
		if(a[i]==((int)sqrt(a[i])*(int)sqrt(a[i])))
			cout<<a[i]<<" ";
	}
	freopen("D:\\baiTapLapTrinh\\test\\Hoanhao.txt","w",stdout);
	for(int i=0;i<n;i++){
		int sum=1;
		for(int j=2;j<sqrt(a[i]);j++)
			if(a[i]%j==0)sum+=j+a[i]/j;
		if(sum==a[i])
			cout<<a[i]<<" ";
	}
}
