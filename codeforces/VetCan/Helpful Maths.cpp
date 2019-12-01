#include<bits/stdc++.h>
using namespace std;
int main(){
	string s;
	cin>>s;
	int a[100],m(0);
	for(int i=0;i<s.size();i++){
		if(s[i]!='+')a[m++]=s[i]-'0';
	}
	sort(a,a+m);
	for(int i=0;i<m-1;i++)printf("%d+",a[i]);
	printf("%d",a[m-1]);
}
