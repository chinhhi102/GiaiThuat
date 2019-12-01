#include<bits/stdc++.h>
using namespace std;
int main(){
	int res(1);
	int maxx=0;
	map<string,int>m;
	string s;
	while(getline(cin,s)){
		if(s[0]=='*'&&s[1]=='*'&&s[2]=='*')break;
		m[s]++;
		maxx=max(maxx,m[s]);
	}
	for(map<string,int>::iterator it=m.begin();it!=m.end();it++){
		if(it->second==maxx)res--;
	}
	if(res)cout<<"Runoff!";else
	for(map<string,int>::iterator it=m.begin();it!=m.end();it++)
		if(it->second==maxx){
			cout<<it->first;
			break;
		}
}
