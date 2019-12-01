#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,l,res=0,vt=0,d,r,g;
	cin>>n>>l;
	while(n--){
		cin>>d>>r>>g;
		if(d>l)break;
		if(vt<d)res+=d-vt;
		if(res%(r+g)<r)res+=r-res%(r+g);
		vt=d;
	}
	if(vt<l)res+=l-vt;
	cout<<res;
}
