#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,res(0);
	scanf("%d",&n);
	string s;
	cin.ignore();
	while(n--){
		getline(cin,s);
		if(s[1]=='+')res++;else res--;
	}
	printf("%d",res);
}
