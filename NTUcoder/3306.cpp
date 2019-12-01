#include<bits/stdc++.h>
using namespace std;
#define int long long
#undef int
int main(int argc, char const *argv[]){
#define int long long
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//    freopen("Electric//00.in","r",stdin);
//    freopen("out.txt","w",stdout);
    int n,k;
    cin>>n>>k;
    n%k?cout<<((float)n/k-n/k<=0.5&&n>k?n/k*10+5:n/k*10+10):cout<<n/k*10;
	return 0;
}

