#include<bits/stdc++.h>
using namespace std;
map<char,int>M;
string s;
int main(){
	getline(cin,s);
	for(int i=0;i<s.size();i++) M[s[i]];
	printf("%d",M.size());
}
