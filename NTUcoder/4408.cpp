#include<bits/stdc++.h>
using namespace std;
#define N 1000001
int main(){
	ios::sync_with_stdio(0);
    int n,k,x;
    long long y,a[N]={},res=0;
    cin>>n>>k;k=k*2+1;
    while(n--){
    	cin>>x>>y;
        a[x]=y;
    }
    for(int i=1;i<N;i++)a[i]+=a[i-1];
    if(k<N){
        for(int i=k;i<N;i++)res=max(res,a[i]-a[i-k]);
        res=max(res,a[k-1]);
    }else res=a[N-1];
	cout<<res;
}
