#include<bits/stdc++.h>
using namespace std;
#define int long long
#undef int
int main(){
#define int long long
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,l=0,r=0,x;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>x;
		l+=x<0;
		r+=x>0;
	}
	cout<<((l+r)<n?-1:min(l,r));
	return 0;
}
