#include<bits/stdc++.h>
using namespace std;
int main(){
	int T, n;
	cin >> T;
	while(T--){
		cin >> n;
		string s1, s2;
		cin >> s1 >> s2;
		int d[26] = {};
		for(int i = 0; i < n; i++){
			d[s1[i] - 'a']++;
			d[s2[i] - 'a']++;
		}
		bool bre = false;
		for(int i = 0; i < 26; i++){
			if(d[i] & 1) bre = true;
		}
		if(bre){
			cout << "No" << endl;
		}else{
			vector<pair<int,int>> res;
			for(int i = 0; i < n; i++){
				if(s1[i] != s2[i]){
					for(int j = i + 1; j < n; j++){
						if(s1[i] == s1[j]){
							swap(s2[i], s1[j]);
							res.push_back({j, i});
							break;
						}else if(s1[i] == s2[j]){
							swap(s1[j], s2[j]);
							res.push_back({j, j});
							swap(s2[i], s1[j]);
							res.push_back({j, i});
							break;
						}
					}
				}
			}
			cout << "Yes" << endl;
			cout << res.size() << endl;
			for(int i = 0; i < res.size(); i++){
				cout << res[i].first + 1<< ' ' << res[i].second + 1<< endl;
			}
		}
	}
}
