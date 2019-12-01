#include<bits/stdc++.h>
using namespace std;
#define INF 1000000
vector<vector<int>> G;
int dem;
stack<int> S;
vector<int> Number, Low;
vector<bool> avail;

void DFSVisit(int u){
	dem++;
	Number[u] = dem;
	Low[u] = INF;
	S.push(u);
	for(int v:G[u]){
		if(!avail[v]) continue;
		if(Number[v] > 0) Low[u] = min(Low[u], Number[v]);
		else{
			DFSVisit(v);
			Low[u] = min(Low[u], Low[v]);
		}
	}
	if(Low[u] >= Number[u]){
		cout << "TP lien thong manh chot " << u << " gom : ";
		while(1){
			int v = S.top();
			S.pop();
			cout << v << " ";
			avail[v] = false;
			if(v == u) break;
		}
		cout << endl;
	}
}

int main(){
	dem = 0;
	int n;
	cin >> n;
	G.resize(n + 1);
	Number.resize(n + 1, 0);
	Low.resize(n + 1, 0);
	avail.resize(n + 1, true);
	int m, x;
	for(int i = 1; i <= n; i++){
		cin >> m;
		for(int j = 0; j < m; j++){
			cin >> x;
			G[i].push_back(x);
		}
	}
	for(int i = 1; i <= n; i++)
		if(avail[i]) DFSVisit(i);
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
