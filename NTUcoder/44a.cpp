#include<bits/stdc++.h>
using namespace std;
#define int long long
#undef int
int main(int argc, char const *argv[]){
#define int long long
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//    freopen("Electric//00.in","r",stdin);
//    freopen("out.txt","w",stdout);
    int n;
    cin>>n;
    if(n==1){
    	cout<<"NO";
    	return 0;
	}
    for(int i=2;i<=sqrt(n);i++)
    	if(n%i==0){
    		cout<<"NO";
    		return 0;
		}
	cout<<"YES";
    return 0;
}
