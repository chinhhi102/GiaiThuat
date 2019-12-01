#include<bits/stdc++.h>
using namespace std;
int main(){
	int sum(0),s1(0),s2(0),a[15000],b[15000];
	string s;
	cin>>s;
	for(int i=0;i<s.size()/2;i++)s1+=s[i]-'A';
	for(int i=s.size()/2;i<s.size();i++)s2+=s[i]-'A';
	for(int i=0;i<s.size()/2;i++){
		a[i]=(s[i]-'A')-26+s1%26+26*(((s[i]-'A')-26+s1%26)<0);
		b[i]=(s[i+s.size()/2]-'A')-26+s2%26+26*(((s[i+s.size()/2]-'A')-26+s2%26)<0);
	}
	for(int i=0;i<s.size()/2;i++){
		printf("%c",(a[i]+b[i])%26+'A');
	}
}
