#include<bits/stdc++.h>
using namespace std;
int main(){
	string s;
	cin>>s;
	printf("%c",s[0]-32*(s[0]>='a'));
	for(int i=1;i<s.size();i++)printf("%c",s[i]);
}
