#include<bits/stdc++.h>
using namespace std;
int main(){
	string s;
	while(getline(cin,s)){
		bool flag(1);
		for(long long i=0;i<s.size();i++){	
			if(s[i-6]=='P'||s[i-6]=='p'){
				if(s[i-5]=='r'||s[i-5]=='R'){
					if(s[i-4]=='o'||s[i-4]=='O'){
						if(s[i-3]=='b'||s[i-3]=='B'){
							if(s[i-2]=='l'||s[i-2]=='L'){
								if(s[i-1]=='e'||s[i-1]=='E'){
									if(s[i]=='m'||s[i]=='M'){
										cout<<"yes"<<endl;flag=0;break;
									}
								}
							}
						}
					}
				}
			}
		}
		if(flag) cout<<"no"<<endl;
	}
}
