#include<bits/stdc++.h>
using namespace std;
#define int long long
#undef int
int main(int argc, char const *argv[]){
#define int long long
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//    freopen("Electric//00.in","r",stdin);
//    freopen("out.txt","w",stdout);
    int m,n,t,d;
 	cin>>m>>n>>t;
 	d=(m>n)?0:(m<n)?n/m:0;
	n=(!(m-1))?n/2:(m-1&&m<1e5)?n-d:n;
	cout<<n*t;
	return 0;
}
