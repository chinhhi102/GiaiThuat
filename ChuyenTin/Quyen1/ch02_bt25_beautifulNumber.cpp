#include<bits/stdc++.h>
using namespace std;
int main(){
	string s;
	cin >> s;
	bool isBeautifuNumber = false;
	if (s == "9") isBeautifuNumber = true;
	int total = 0;
	for(int i = 0; i < s.size(); i++) total += (s[i] - '0');
	if(total == 9) isBeautifuNumber = true;
	cout << (isBeautifuNumber ? "YES" : "NO");
}
