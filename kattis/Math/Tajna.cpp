#include<bits/stdc++.h>
using namespace std;
int main(){
	string s;
	int len;
	cin>>s;
	len=(int)sqrt(s.size());
	while(len*(s.size()/len)!=s.size())len--;
	for(int i=0;i<len;i++){
		for(int j=i;j<s.size();j+=len){
			cout<<s[j];
		}
	}
}
