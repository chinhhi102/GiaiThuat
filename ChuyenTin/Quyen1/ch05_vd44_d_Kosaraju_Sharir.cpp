#include<bits/stdc++.h>
using namespace std;
#define INF 1000000
vector<vector<vector<int>>> G;
vector<bool> avail;
vector<int> List;
void DFSVisit(int u){
	avail[u] = false;
	for(int v:G[u][0])
		if(avail[v]) DFSVisit(v);
	List.push_back(u);
}
void Enum(int u){
	avail[u] = false;
	cout << u << " ";
	for(int v:G[u][1])
		if(avail[v]) Enum(v);
}
int main(){
	int n;
	cin >> n;
	G.resize(n + 1, vector<vector<int>>(2));
	avail.resize(n + 1, true);
	int m, x;
	for(int i = 1; i <= n; i++){
		cin >> m;
		for(int j = 0; j < m; j++){
			cin >> x;
			G[i][0].push_back(x);
			G[x][1].push_back(i);
		}
	}
	for(int i = 1; i <= n; i++)
		if(avail[i]) DFSVisit(i);
	avail.assign(n + 1, true);
	int k = 0;
	for(int i = n - 1; i >= 0; i--){
		if(!avail[List[i]]) continue;
		cout << "Strongly connected componet " << ++k << ": ";
		Enum(List[i]);
		cout << endl;
	}
}
/*
11
2 2 8
1 3
1 4
2 2 5
1 6
1 7
1 5
1 9
2 4 10
2 8 11
1 8
*/
