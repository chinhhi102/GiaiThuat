#include<bits/stdc++.h>
using namespace std;
#define int long long
#undef int
int main(int argc, char const *argv[]){
#define int long long
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//    freopen("Electric//00.in","r",stdin);
//    freopen("out.txt","w",stdout);
    int n,k,m;
    cin>>n>>m;    
    if (m%2)
		cout<<-1;
	else{
    	if((m>=2*n)&(m<=4*n)) {
    		k=m/2-n;
    		cout<<n-k<<' '<<k;
		}
    	else cout<<-1;
	}
    return 0;
}
