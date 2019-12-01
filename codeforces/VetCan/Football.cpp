#include<bits/stdc++.h>
using namespace std;
int main(){
	string s;
	cin>>s;
	int k(1);
	for(int i=1;i<s.size();i++){
		if(s[i]==s[i-1])k++;else k=1;
		if(k==7){printf("YES");return 0;}
	}
	printf("NO");
}
