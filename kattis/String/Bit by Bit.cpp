#include <bits/stdc++.h>
using namespace std;
int main(){
	int n;
	string syn;
	while(cin>>n&&n){
		string res;
		res.resize(32,'?');
		while(n--){
			cin>>syn;
			if(syn=="CLEAR"){
				int id;
				cin>>id;
				res[id]='0';
			}else if(syn=="SET"){
				int id;
				cin>>id;
				res[id]='1';
			}else if(syn=="OR"){
				int i,j;
				cin>>i>>j;
				res[i]=(res[i]=='1'||res[j]=='1')?'1':(res[i]=='0'&&res[j]=='0')?'0':'?';
			}else{
				int i,j;
				cin>>i>>j;
				res[i]=(res[i]=='1'&&res[j]=='1')?'1':(res[i]=='0'||res[j]=='0')?'0':'?';
			}
		}
		cout<<string(res.rbegin(),res.rend())<<endl;
	}
}
