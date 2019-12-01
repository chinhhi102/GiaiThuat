#include<bits/stdc++.h>
using namespace std;
#define int long long

#undef int
int main(){
#define int long long
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n;
	cin>>n;
	int res=0,last=0,x,d=0;
	for(int i=0;i<n;i++){
		cin>>x;
		if(x>last){
			d++;
			res=max(res,d);
		}else
			d=1;
		last=x;
	}
	cout<<res;
	return 0;
}
