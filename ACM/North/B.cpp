#include<bits/stdc++.h>
using namespace std;
int main(){
	int n, x;
	cin >> n;
	vector<int> v;
	int t = 0;
	for (int i = 0; i < n; i++){
		cin >> x;
		t += x;
		if(x%2 == 0){
			v.push_back(x/2);
			v.push_back(x/2);
		}else v.push_back(x);
	}
	sort(v.begin(), v.end());
	map<int,bool> res, temp;
	int d = t/2;
	for(int i = 0; i < v.size(); i++){
		x = v[i];
		temp[x] = true;
		for(auto u:res){
			temp[u.first + x] = true;
			if(u.first + x >= d) break;
		}
		res.clear();
		res = temp;
	}
	int SS = 1e9;
	int id;
	for(auto u:res){
//		cout << u.first << endl;
		if(SS >= abs(u.first - d)){
			SS = abs(u.first - d);
			id = u.first;
		}
	}
	cout << max(id, t - id);
}
