#include<bits/stdc++.h>
using namespace std;
int main(){
	int x,temp,a[1000]={},k;
	string s;
	scanf("%d",&x);
	while(scanf("%d",&temp)){
		if(!(temp+1))break;
		int num(0);
		getline(cin,s);
		for(int i=1;i<s.size();i++){
			if(s[i]==' '){
				a[num]=temp;
				num=0;
				continue;
			}
			num=num*10+(s[i]-'0');
			if(s[i+1]=='\0'){
				a[num]=temp;
				break;
			}
		}
	}
	while(x){
		printf("%d ",x);
		x=a[x];
	}
}
