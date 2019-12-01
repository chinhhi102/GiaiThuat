#include<bits/stdc++.h>
using namespace std;
int main(){
	bool f(0);
	string s;
	cin>>s;
	if(s[1]==NULL){printf("%c",s[0]>'Z'?s[0]-32:s[0]+32);return 0;}
	for(int i=1;i<s.size();i++)if(s[i]<='Z')f=1;else{f=0;break;}
	if(f&&s[0]<='Z'){for(int i=0;i<s.size();i++)printf("%c",s[i]+32);return 0;}
	if(s[0]>'Z'&&f)
	for(int i=0;i<s.size();i++)if(s[i]>'Z')printf("%c",s[i]-32);else printf("%c",s[i]+32);
	else cout<<s;
}
