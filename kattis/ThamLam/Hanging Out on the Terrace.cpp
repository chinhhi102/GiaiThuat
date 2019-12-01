#include<bits/stdc++.h>
using namespace std;
int main(){
	int l,x,pas(0),den(0),peo;
	scanf("%d%d",&l,&x);
	while(x--){
		string s;
		cin>>s>>peo;
		if(s[0]=='e')if(pas+peo>l)den++;else pas+=peo;
		if(s[0]=='l')pas-=peo;
	}
	printf("%d",den);
}
