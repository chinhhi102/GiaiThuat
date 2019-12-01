#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	scanf("%d",&n);
	cin.ignore();
	while(n--){
		char res[1000]="",text[1000]="";
		gets(text);
		res[0]=text[0];
		for(int i=0;i<strlen(text);i++){
			if(text[i]!=res[i%strlen(res)]){
				for(int j=strlen(res);j<i;j++)res[strlen(res)]=text[j];
				if(text[i]!=res[0])res[strlen(res)]=text[i];
			}
		}
		cout<<strlen(res)<<endl;
	}
} 
