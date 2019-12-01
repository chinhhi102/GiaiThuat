#include<bits/stdc++.h>
using namespace std;
#define MAXN 1000010
int composite[MAXN];
bool isprime[MAXN],dp[MAXN];
vector<int> primes;
void sieve_coprime(){
	memset(isprime,1,sizeof isprime);
	memset(composite,0,sizeof composite);
	isprime[0]=isprime[1]=0;
	composite[0]=composite[1]=0;
	for(int i=2;i<MAXN;i++){
		if(isprime[i]){
			for(int j=i*2;j<MAXN;j+=i){
				isprime[j]=0;
			}
			primes.push_back(i);
		}
	}
	
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	string res[]={"BACH","KHOA"};
	sieve_coprime();
	memset(dp,0,sizeof dp);
	for(int i=2;i<MAXN;i++){
		composite[i]=1;
		int PF_index = 0, PF = primes[PF_index];
		int d=0;
		int N=i, ans = N;
		while(PF*PF <= N){
			if (N % PF == 0)
				ans -= ans / PF;
			while(N%PF == 0){
				N/=PF;
			}
			PF = primes[++PF_index];
		}
		if(N != 1)
			ans -= ans / N;
		composite[i] = ans;
//		cout << i << ' ' << ans << endl;
	}
	dp[1]=0;
	int d;
	for(int i=2;i<MAXN;i++){
		d=(i>0)+(i/10>0)+(i/100>0)+(i/1000>0)+(i/10000>0)+(i/100000>0)+(i/1000000>0);
		dp[i]=!(dp[i-1]||dp[i-d]||dp[i - composite[i]]);
	}
	int n;
	cin>>n;
	int x;
	for(int i=0;i<n;i++){
		cin>>x;
		cout<<res[dp[x]]<<endl;
	}
}
