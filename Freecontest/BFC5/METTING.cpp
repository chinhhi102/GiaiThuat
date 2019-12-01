#include<bits/stdc++.h>
using namespace std;
#define int long long
#undef int
int main(){
#define int long long
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n;
	char c;
	cin>>n>>c;
	string s;
	for(int i=0;i<n;i++){
		cin>>s;
		bool w=1;
		for(int j=0;j<s.size();j++)
			if(s[j]==c){
				w=0;
				break;
			}
		if(w)
			cout<<s<<endl;
	}
	return 0;
}
