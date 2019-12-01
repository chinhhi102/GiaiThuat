#include<bits/stdc++.h>
using namespace std;
int main(){
	string pass,text;
	cin>>pass>>text;
	for(int i=0,vt=0;i<text.size();i++){
		for(int j=vt+1;j<pass.size();j++)if(pass[j]==text[i]&&pass[j]!=pass[vt]){
			printf("FAIL");
			return 0;
		}
		if(pass[vt]==text[i])vt++;
		if(vt==pass.size()){
			printf("PASS");
			return 0;
		}
	}
	printf("FAIL");
}
