#include <bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int T;
	cin>>T;
	while(T--){
		int customers;
		cin>>customers;
		double total[customers]={};
		for(int i=0;i<customers;i++){
			int sz;
			double size;
			cin>>sz;
			for(int j=0;j<sz;j++)
				cin>>size,total[i]+=size;
		}
		sort(total,total+customers);
		double res=0,sum=0;
		for(int i=0;i<customers;i++){
			sum+=total[i];
			res+=sum;
		}
		res/=customers;
		cout<<setprecision(6)<<fixed<<res<<endl;
	}
}
