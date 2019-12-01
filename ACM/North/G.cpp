#include<bits/stdc++.h>
using namespace std;
int main(){
#define int long long
	int n,s,x;
	cin >> n >> s;
	map<int,vector<int>> m;
	for(int i = 0; i < n; i++){
		cin >> x;
		m[x].push_back(i+1);
	}
	map<int,vector<int>>::iterator i1 = m.upper_bound(s), res1, res2;
	bool f = false;
	int res = 0;
	for(;i1 != m.begin(); i1--){
		if(i1->second.size() < 2) continue;
		map<int,vector<int>>::iterator i2 = m.upper_bound(s/i1->first);
		if(i2 == m.begin() && i1->first*i2->first > s) continue;
		i2--;
		while(i2 != m.begin() && i2->second.size() < 2) i2--;
		if(i1 == i2 && i1->second.size() <= 4) continue;
		if(i1->first*i2->first >= res && i1->first*i2->first <= s){
			f = true;
			res = i1->first*i2->first;
			res1 = i1;
			res2 = i2;
		}
	}
	if(!f){
		cout << -1;
		return 0;
	}
	int arr[] = {res1->second[0], res1->second[1], res2->second[0], res2->second[1]};
	sort(arr, arr+4);
	for(int i = 0; i < 4; i++)
		cout << arr[i] << ' ';
}
/*
8 10
1 1 2 2 3 3 4 4 5 5
*/
