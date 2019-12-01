#include<bits/stdc++.h>
using namespace std;
int main(){
	string n;
	cin >> n;
	vector<int> l, r;
	int div, nho = 0;
	string temp;
	int t = 0;
	while(n != ""){
		div = 0;
		temp = "";
		for(int i = 0; i < n.size(); i++){
			div = div*10 + (n[i] - 48);
			if(div > 2){
				temp += char(div/3 + 48);
				div %= 3;
			}
		}
		div += nho;
		div %= 3;
		if(div == 2){
			r.push_back(t);
			nho = 1;
		}else{
			if(div) l.push_back(t);
			nho = 0;
		}
		n = temp;
		t++;
	}
	if(nho) l.push_back(t);
	if(l.size()) for(int i = 0; i < l.size(); i++){ cout << l[i] << " ";}
	else cout << -1;
	cout << endl;
	if(r.size()) for(int i = 0; i < r.size(); i++){ cout << r[i] << " ";}
	else cout << -1;
}
