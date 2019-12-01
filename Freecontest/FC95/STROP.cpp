#include<bits/stdc++.h>
using namespace std;
#define int long long
int S[2][100005]={},T[2][100005]={};
#undef int
int main(){
#define int long long
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	string s;
	cin>>s;	
	for(int i=0;i<s.size();i++){
		S[s[i]=='B'][i+1]=S[s[i]=='B'][i]+1;
		S[!(s[i]=='B')][i+1]=S[!(s[i]=='B')][i];
	}
	cin>>s;
	for(int i=0;i<s.size();i++){
		T[s[i]=='B'][i+1]=T[s[i]=='B'][i]+1;
		T[!(s[i]=='B')][i+1]=T[!(s[i]=='B')][i];
	}
	int q;
	cin>>q;
	for(int i=0;i<q;i++){
		int a,b,c,d;
		cin>>a>>b>>c>>d;
		int x,y,t1,t2;
		x=(S[0][b]-S[0][a-1]);
		y=(S[1][b]-S[1][a-1]);
		t1=x*2+y;
		x=(T[0][d]-T[0][c-1]);
		y=(T[1][d]-T[1][c-1]);
		t2=x*2+y;
		cout<<(abs(t1-t2)%3?"NO":"YES")<<endl;
	}
	return 0;
}
