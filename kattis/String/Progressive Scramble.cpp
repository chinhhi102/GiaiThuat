#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	scanf("%d",&n);
	while(n--){
		string key,text;
		int mes[500],res[500];
		cin>>key;cin.ignore();
		getline(cin,text);
		for(int i=0;i<text.size();i++){
				if(text[i]==' ')mes[i]=0;
				else mes[i]=text[i]-'a'+1;
		}
		if(key[0]=='e'){
			for(int i=1;i<text.size();i++)mes[i]+=mes[i-1];
			for(int i=0;i<text.size();i++)mes[i]%=27;
		}
		if(key[0]=='d'){
			for(int i=1;i<text.size();i++)while(mes[i]<mes[i-1])mes[i]+=27;
			for(int i=text.size();i>0;i--)mes[i]-=mes[i-1];
		}
		for(int i=0;i<text.size();i++){
			res[i]=mes[i]+'a'-1;
			if(!mes[i])res[i]=' ';
		}
		for(int i=0;i<text.size();i++)printf("%c",res[i]);printf("\n");
	}
}
