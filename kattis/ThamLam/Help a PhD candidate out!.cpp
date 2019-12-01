#include<bits/stdc++.h>
using namespace std;
int sum(string s){
	int res(0),temp(0);
	for(int i=0;i<s.size();i++){
		if(s[i]=='+'){res+=temp;temp=0;continue;}
		temp=temp*10+(s[i]-'0');
	}
	res+=temp;
	return res;
}
int main(){
	int n;
	scanf("%d",&n);
	cin.ignore();
	while(n--){
		string s;
		cin>>s;
		if(s[0]=='P'){cout<<"skipped"<<endl;continue;}
		cout<<sum(s)<<endl;
	}
}
