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
    int l=1,r=1;
   	cout<<1;
   	for(int i=1;i<n;i++){
   		r=l+r;
   		l=r-l;
   		cout<<' '<<l;
	}
    return 0;
}
