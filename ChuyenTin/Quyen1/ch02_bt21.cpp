#include<bits/stdc++.h>
using namespace std;
map<string,char> biToHex;
void trans(string binaryString, int id){
	if(id == 4){
		int d = biToHex.size();
		biToHex[binaryString] = (d > 9 ? (d - 10) + 'A' : d + '0');
		return;
	}
	for(char i = '0'; i <= '1'; i++){
		binaryString[id] = i;
		trans(binaryString, id+1);
	}
}
int main(){
	string binaryString;
	binaryString.resize(4);
	trans(binaryString, 0);	
	string s;
	cin >> s;
	string temp = "", res = "";
	for(int i = s.size() - 1; i >= 0; i--){
		temp = s[i] + temp;
		if(temp.size() == 4){
			res = biToHex[temp] + res;
			temp = "";
		}
	}
	if(temp.size()){
		while(temp.size() < 4)
			temp = '0' + temp;
		res = biToHex[temp] + res;
	}
	cout << res << endl;
}
