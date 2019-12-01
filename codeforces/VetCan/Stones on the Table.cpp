#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,res(0);
	string s;
	scanf("%d",&n);
	cin.ignore();
	cin>>s;
	for(int i=1;i<n;i++){
		if(s[i]==s[i-1])res++;
	}
	printf("%d",res);
}
