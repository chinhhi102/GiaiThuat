#include<bits/stdc++.h>
using namespace std;
#define int long long

#undef int
int main(){
#define int long long
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	string s;
	cin>>s;
	int res=1,sz=s.size();
	for(int i=1;i<=sz;i++){
		if(sz%i)continue;
		bool f=true;
		string tmp=string(s.begin(),s.begin()+(sz/i));
		for(int j=sz/i;j<sz;j+=sz/i){
			if(tmp!=string(s.begin()+j,s.begin()+j+sz/i)){
				f=false;
				break;
			}
		}
		if(f){
			res=i;
		}
	}
	cout<<res<<string(s.begin(),s.begin()+(sz/res));
	return 0;
}
