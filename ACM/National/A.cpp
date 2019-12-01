#include<bits/stdc++.h>
using namespace std;
#define int long long
#define MAX 100010
vector<string> s;
vector<vector<bool>> use;
int res[MAX] = {};
int result = (int)1e18;
int a, c;
#undef int
int main(){
#define int long long
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> c >> a;
	s.resize(c + 1);
	use.resize(c + 1, vector<bool>(a, false));
	char t;
	for(int i = 0 ; i < c; i++)
		cin >> s[i];
	s[c].resize(a, '.');
	s[0][0] = '.';
	priority_queue<pair<int,pair<int,int>>> pq;
	pq.push({0, {0, 0}});
	int x, y, se;
	int fo = 0;
	while(!pq.empty()){
		pair<int, pair<int,int>> cur = pq.top();
		pq.pop();
		se = cur.first;
		x = cur.second.first;
		y = cur.second.second;
		if(x == c){
			fo = se;
			break;
		}
		if(use[x][y]) continue;
		use[x][y] = true;
		if((x - 1) >= 0 && s[(x - 1)][(y - 1 + 2*a) % a] == '.' && s[(x - 1)][(y + 2*a) % a] == '.' && !use[(x - 1)][(y - 1 + 2*a) % a]){
			pq.push({se - 1, {x - 1, (y - 1 + 2*a) % a}});
		}
		if(s[x][(y - 2 + 3*a) % a] == '.' && s[x][(y - 1 + 2*a) % a] == '.' && !use[x][(y - 2 + 2*a) % a]){
			pq.push({se - 1, {x, (y - 2 + 2*a) % a}});
		}
		if(s[x][(y - 1 + 2*a) % a] == '.' && s[x][(y + 2*a) % a] == '.' && !use[x][(y - 1 + 2*a) % a]){
			pq.push({se - 1, {x, (y - 1 + 2*a) % a}});
		}
		if(x + 1 <= c && s[x + 1][(y - 1 + 3*a) % a] == '.' && s[x + 1][(y + 2*a) % a] == '.' && !use[x + 1][(y - 1 + 2*a) % a]){
			pq.push({se - 1, {x + 1, (y - 1 + 2*a) % a}});
		}
		
	}
	cout << (fo ? -fo : -1) << endl;
}
/*
5 5
G....
.....
.....
.....

1 2
G M

5 3
G..
...
...
...
M..

3 8
G.......
....G...
........
*/
