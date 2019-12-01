#include<bits/stdc++.h>
using namespace std;
int main(){
	char cip[501],key[1002];
	gets(cip);gets(key);
	int t=strlen(key);
	for(int i=0;i<strlen(cip);i++)printf("%c",key[i+t]=cip[i]-(key[i]-'A')+26*(cip[i]-(key[i]-'A')<'A'));
}
