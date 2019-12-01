#include<bits/stdc++.h>
using namespace std;
#define int long long

#undef int
int main(){
#define int long long
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int a,b,c,res=0;
	cin>>a>>b>>c;
	if(c==0){cout<<0;return 0;}
	for(int i=a;i<=b;i++)
		if(i%c==0)
			res++;
	cout<<res;
	return 0;
}
