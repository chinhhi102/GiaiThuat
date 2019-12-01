#include<bits/stdc++.h>
using namespace std;
int distributeCandy(std::vector<int> age)
{
	int t=1,g=1,b=0,n=age.size();
	int dp[n+1]={};
	int total=0;
	dp[0]=0;
	dp[1]=1;
	bool f=0;
	for(int i=1;i<n;i++){
		if(age[i]>age[i-1]){
			t++;
			g=1;
			b=0;
			f=1;
		}else if(age[i]<age[i-1]){
			t=1;
			g++;
			b=0;
		}else{
			t=1;
			g=1;
			b++;
		}
		int sub=max(t,g);
//		cout<<dp[i+1]<<' ';
		if(sub==1){
			dp[i+1]=dp[i]+1;
		}
		else{
			if(t>1){
				dp[i+1]=dp[i]+t;
			}else{
				if(f){
					g--;
					f=0;
				}
				dp[i+1]=dp[i]+g;
			}
//			dp[i+1]=dp[i-sub+1]+(sub*(sub+1)/2);
		}
		cout<<dp[i+1]<<endl;
	}
	return dp[n];
}

int main(){
	vector<int> v;
	int n,x;
	cin>>n;
	for(int i = 0; i < n; i++){
		cin>>x;
		v.push_back(x);
	}
	cout<<distributeCandy(v);
}
/*
4
1 2 3 4

4
4 3 2 1

5
1 2 1 2 3

6
6 5 4 3 4 2 1

6
1 1 2 2 1 1

10
2 4 2 6 1 7 8 9 2 1 

13
1 2 3 4 5 4 3 4 5 5 5 6 7

13
7 6 5 4 3 4 5 4 3 3 3 2 1

23
6 5 4 3 4 3 2 1 2 3 4 3 4 5 5 5 6 4 2 1 6 5 4
*/
