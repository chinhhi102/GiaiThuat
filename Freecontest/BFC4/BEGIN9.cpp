#include<bits/stdc++.h>
using namespace std;
#define int long long

#undef int
int main(){
#define int long long
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	string a,b;
	cin>>a>>b;
	if(b.size()==1&&b[0]=='0'){
		cout<<"1"<<endl;
		return 0;
	}
	int x=a[a.size()-1]-'0';
	int y;
	if(b.size()==1)
		y=b[0]-'0';
	else
		y=(b[b.size()-2]-'0')*10+(b[b.size()-1]-'0');
	int res=1;
	for(int i=0;i<(y%4+4);i++)
		res*=x;
	cout<<res%10;
	return 0;
}
