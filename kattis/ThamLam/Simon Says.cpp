#include<bits/stdc++.h>
using namespace std;
int main(){
	string s;
	int n;
	cin>>n;
	while(n--){
		cin.ignore();
		getline(cin,s);
		for(int i=0;i<s.size();i++){
			if(s[i]=='i'&&s[i+1]=='m'&&s[i+2]=='o'&&s[i+3]=='n'&&s[i+4]==' '&&s[i+5]=='s'&&s[i+6]=='a'&&s[i+7]=='y'&&s[i+8]=='s'){
				for(int j=i+10;j<s.size();j++)cout<<s[j];
				break;
			}
		}
		cout<<endl;
	}
}
