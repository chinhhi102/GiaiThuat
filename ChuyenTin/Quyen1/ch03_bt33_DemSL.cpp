#include<bits/stdc++.h>
using namespace std;
int main(){
	set<string> c;
	string s;
	cin >> s;
	for(int i = 1; i <= s.size(); i++){
		for(int j = 0; j <= s.size() - i; j++)
			c.insert(string(s.begin() + j, s.begin() + j + i));
	}
	cout << c.size();
}
/*
abab
aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa
*/
