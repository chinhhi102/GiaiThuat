#include<bits/stdc++.h>
using namespace std;
#define int long long

#undef int
int main(){
#define int long long
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int T;
	cin>>T;
	while(T--){
		int n,x,sum1=0,sum2=0,maxx=0;
		bool f=0;
		cin>>n;
		for(int i=0;i<n;i++){
			cin>>x;
			if(x>=0)
				f=1;
			if(f){
				if(sum1<0)
					sum1=0;
				sum1+=(x>0?x:0);
			}
			else
				sum1=max(sum1<0LL?sum1:(int)-10000000,x);
			maxx=max(maxx+x,0LL);
			sum2=max(sum2,maxx);
		}
		cout<<sum1<<' '<<(sum1>=0?sum2:sum1)<<endl;
	}
	return 0;
}
