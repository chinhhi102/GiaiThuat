#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,q;
int a[1000005]={};
int st[4*1000005]={};
#undef int
int main(){
#define int long long
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("TESTINCPOS\\04.in","r",stdin);
	freopen("res.txt","w",stdout);
	cin>>n>>q;
	int res=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(i>1)
			st[i-1]=a[i-1]-a[i],res+=st[i-1]>0;
	}
	while(q--){
		int l,r,x;
		cin>>l>>r>>x;
		if(l>1){
			res-=st[l-1]>0;
			st[l-1]+=-x;
			res+=st[l-1]>0;
		}
		if(r<n){
			res-=st[r]>0;
			st[r]+=x;
			res+=st[r]>0;
		}
		cout<<res<<endl;
	}
	return 0;
}
