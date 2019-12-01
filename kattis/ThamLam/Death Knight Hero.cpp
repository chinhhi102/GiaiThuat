#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,res(0);
	scanf("%d",&n);
	cin.ignore();
	while(n--){
		string s;
		int f=1;
		cin>>s;
		for(int i=0;i<s.size();i++)if(s[i]=='C'&&s[i+1]=='D'){f=0;break;}
		if(f)res++;
	}
	printf("%d",res);
}
