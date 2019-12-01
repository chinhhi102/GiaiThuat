#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	string s;
	while(cin>>n){
		if(!n)break;
		cin.ignore();
		getline(cin,s);
		for(int i=0;i<s.size();i++){
			if(s[i]==' ')s.erase(i,1),i--;
			else s[i]=s[i]>'Z'?s[i]-32:s[i];
		}
		int m(0),tmp(0);
		string res=s;
		for(int i=0,t=0;i<s.size();i++){
			res[t]=s[i];
			t+=n;
			if(t>s.size()-1)t=++tmp;
		}
		for(int i=0;i<s.size();i++)cout<<res[i];
		cout<<endl;
	}
}
