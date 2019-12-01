#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++) cin>>a[i];
	sort(a,a+n);
	int res=0;
	for(int i=n-1,j=1;i>=0;i--,j++){
		res=max(res,a[i]+j);
	}
	cout<<res+1;
	return 0;
}
