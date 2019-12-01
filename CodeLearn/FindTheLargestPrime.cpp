#include<bits/stdc++.h>
using namespace std;
#define MAXN 10000010
bool isprime(int n){
	if(n<2)
		return false;
	for(int i=2;i<=sqrt(n);i++)
		if(n%i==0)
			return false;
	return true;
}
bool cmp(int a, int b){
	return a>b;
}
bool use[10];
int maxx=-1;
void dfs(vector<int> digits, int n, int x){
	if(isprime(x))
		maxx=max(maxx,x);
	for(int i=0;i<n;i++){
		if(!use[i]){
			use[i]=true;
			dfs(digits,n,(x*10)+digits[i]);
			use[i]=false;
		}
	}
}
int findTheLargestPrime(std::vector<int> digits)
{
	memset(use, 0, sizeof use);
	int n = digits.size();
	sort(digits.begin(), digits.end(), cmp);
	for(int i=0; i<n; i++){
		use[i]=true;
		dfs(digits,n,digits[i]);
		use[i]=false;
	}
	return maxx;
}
int main(){
	int n;
	cin>>n;
	vector<int> digits(n);
	for(int i=0;i<n;i++)
		cin>>digits[i];
	cout<<findTheLargestPrime(digits);
}
