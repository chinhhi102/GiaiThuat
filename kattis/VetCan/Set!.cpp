#include<bits/stdc++.h>
using namespace std;
map<int,string>M;
string s;
bool flag(0);
bool tes(string a,string b,string c){
	int d(0),k(0),n(0);
	for(int i=0;i<4;i++){
		if(a[i]==b[i])d++;
		if(a[i]==c[i])k++;
		if(b[i]==c[i])n++;
	}
	if(d==k&&d==n){
		for(int i=0;i<=3;i++){
			if(a[i]==b[i]&&a[i]!=c[i])return 0;
		}
		if(d==k&&d==n)return 1;
	}
	return 0;
}
int main(){
	for(int i=1;i<=12;i++){
		cin>>s;
		M[i]=s;
	}
	for(map<int,string>::iterator i=M.begin();i!=M.end();i++){
		for(map<int,string>::iterator j=M.begin();j!=M.end();j++){
			if(j->first<=i->first)continue;
			for(map<int,string>::iterator k=M.begin();k!=M.end();k++){
				if(k->first<=j->first)continue;
				if(tes(i->second,j->second,k->second)){
					printf("%d %d %d\n",i->first,j->first,k->first);
					flag=1;
				}
			}
		}
	}
	if(!flag)printf("no sets");
}
