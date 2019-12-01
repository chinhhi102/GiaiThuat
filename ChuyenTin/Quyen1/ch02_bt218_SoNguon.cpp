#include<bits/stdc++.h>
using namespace std;
string s, kq;

string sub(string a, string b){
	while(a.size() < b.size()) a = '0' + a;
	while(b.size() < a.size()) b = '0' + b;
	int nho = 0, t;
	string res = "";
	if(a >= b)
		for(int i = a.size() - 1; i >= 0; i--){
			t = a[i] - b[i] - nho;
			if(t < 0){
				t += 10;
				nho = 1;
			}else nho = 0;
			res = char(t + 48) + res;
		}
	while(res.size() && res[0] == '0') res = string(res.begin() + 1, res.end());
	return res;
}
string toString(int x){
	string res = "";
	while(x){
		res = char(x%10 + '0') + res;
		x /= 10;
	}
	return res;
}
void tim(){
	int w;
	for(int i = 9*s.size(); i >= 0; i--){
		string t = toString(i);
		kq = sub(s, t);
		if(kq != ""){
			w = 0;
			for(int j = 0; j < kq.size(); j++) w += kq[j] - 48;
			if(w == i) return;
		}
	}
	kq = "0";
}
int main(){
	int n;
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> s;
		tim();
		cout << kq << endl;
	}
}
