#include<bits/stdc++.h>
using namespace std;
int main(){
	map<string,int>m;
	int n,t(0);
	cin>>n;
	cin.ignore();
	while(n--){
		string s,tmp="";
		getline(cin,s);
		for(int j=0;j<s.size();j++){
			if(s[j]==' ')break;
			tmp+=s[j];
		}
		if(m[tmp]==0&&t<12)cout<<s<<endl,t++;
		m[tmp]++;
	}
}
