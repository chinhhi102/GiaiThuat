#include<bits/stdc++.h>
using namespace std;
#define int long long
int sol(map<int,int> m, int tong, int co){
	if(m.size() == 0) return (int)1e18;
	int res = (int)1e18;
	int suf = tong;
	int bo = 0;
	int sl = 0;
	map<int,int>::iterator it = m.begin();
	int last = it->first;
	int pre = 0;
	for(auto t:m){
		suf -= t.first*t.second;
		co -= t.second;
		suf -= co*t.first;
		pre += sl*(t.first - last);
		while(it->first < t.first && it->first < t.first - it->first){
			bo += it->first*it->second;
			pre -= (t.first - it->first)*it->second;
			sl -= it->second;
			it++;
		}
		res = min(res, pre + suf + bo);
		suf += co*t.first;
		sl += t.second;
		last = t.first;
	}
	return res;
}

#undef int
int main(){
#define int long long
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int n;
	cin >> n;
	map<int,int> m1, m2;
	int sumA = 0, sumB = 0;
	int numD = 0, numA = 0;
	for(int i = 0; i < n; i++){
		int x;
		cin >> x;
		if(x > 0){
			m1[x]++;
			sumA += x;
			numD++;
		}
		if(x < 0){
			m2[-x]++;
			sumB += -x;
			numA++;
		}
	}
	int minduong = sol(m1, sumA, numD);
	int minam = sol(m2, sumB, numA);
	if(sumA + sumB)
		cout << min(minduong + sumB, minam + sumA);
	else
		cout << 0;
}
/*
5
1 1 1 1 5
*/
