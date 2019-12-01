#include<bits/stdc++.h>
using namespace std;
int main(){
	string temp="hello",s;
	cin>>s;
	for(int i=0,j=0;i<s.size();i++){
		if(s[i]==temp[j])j++;
		if(j==5){printf("YES");return 0;}
	}
	printf("NO");
}
