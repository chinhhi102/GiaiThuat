#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[500000]={};
#undef int
int main(){
#define int long long
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,m;
	cin>>n>>m;
	int x,y;
	for(int i=0;i<m;i++){
		cin>>x>>y;
		a[x]++;
		a[y]++;
	}
	int total=0;
	for(int i=1;i<=n;i++)
		total+=a[i];
	cout<<total/2;
	return 0;
}
