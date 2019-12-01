#include<bits/stdc++.h>
using namespace std;
#define int long long
int gt(int x){
	if(x==1)return 1;
	return x*gt(x-1);
}
#undef int
int main(){
#define int long long
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	map<int,int> m;
	int n,x,last=0,res=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>x;
		m[i]=x;
		res+=min(m[i],m[i-1]);
		m[i]-=min(m[i],m[i-1]);
		res+=m[i]/2;
		m[i]-=m[i]/2*2;
	}
	cout<<res;
	return 0;
}
