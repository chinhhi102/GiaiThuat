#include<bits/stdc++.h>
using namespace std;
int main1(){
    int f[81]={10,3};
    for(int i=2;i<81;i++){
        stringstream ss;
        ss<<f[i-1];
        string s=ss.str();
        for(int j=s.size()-1;j>=0;j--)f[i]=f[i]*10+s[j]-48;
        f[i]+=2;
    }
    long long n;
    scanf("%lld",&n);
    printf("%d",(n>1)?f[(long long)(n-1)%81]:-1);
}
/*--------------cach 2---------------*/
long long n,x,a[100]={8,10};
long long rev(int a){
	int t,dao=a%10;
	while (a/=10)t=a%10,dao=dao*10+t;
	return dao+2;
}
int main(){
	scanf("%lld",&n);
	for (long long i=2;i<=81;i++){
		a[i]=rev(a[i-1]);
	}
	printf("%d",a[n%81]);
}
