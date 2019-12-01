#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	string s;
	scanf("%d",&n);
	cin.ignore();
	while(n--){
		getline(cin,s);
		if(s.size()>10)printf("%c%d%c\n",s[0],s.size()-2,s[s.size()-1]);
		else cout<<s<<endl;
	}
}
