#include<bits/stdc++.h>
using namespace std;

int main(){
#define int long long
	string s;
	cin >> s;
	int d[26] = {};
	for(int i = 0; i < s.size(); i++)
		d[s[i] - 'a']++;
	int kq = 1;
	for(int i = 1; i <= s.size(); i++)
		kq *= i;
	for(int i = 0; i < 26; i++)
		for(int j = 1; j <= d[i]; j++)
			kq /= j;
	cout << kq;
}
