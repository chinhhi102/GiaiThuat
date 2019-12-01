#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin>>n;
	int a[n][n];
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			cin>>a[i][j];
	int row[n]={},col[n]={},sum[2]={};
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			row[i]+=a[i][j];
			col[j]+=a[i][j];
			sum[a[i][j]%2]+=a[i][j];
		}
	}
	bool f=1;
	for(int i=0;i<n&&f;i++)
		if(((row[i]+1)%2&&(col[i])%2))continue;
		else f=0;
	f?cout<<sum[0]:cout<<sum[1];
	return 0;
}
