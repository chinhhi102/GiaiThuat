#include<bits/stdc++.h>
using namespace std;
int main(){
#define int long long
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int n;
	cin >> n;
	vector<pair<int,int>> pos(n);
	vector<int> c(n), k(n);
	for(int i = 0; i < n; i++)
		cin >> pos[i].first >> pos[i].second;
	for(int i = 0; i < n; i++)
		cin >> c[i];
	for(int i = 0; i < n; i++)
		cin >> k[i];
	vector<int> power_stations;
	vector<pair<int,int>> connections;
	vector<int> parent(n, -1);
	vector<bool> done(n, false);
	int res = 0;
	for(int i = 0; i < n; i++){
		int mi = 200000000000;
		int u = -1;
		for(int j = 0; j < n; j++){
			if(done[j]) continue;
			if(c[j] < mi){
				mi = c[j];
				u = j;
			}
		}
		res += mi;
		done[u] = true;
		if(parent[u] == -1) power_stations.push_back(u);
		else connections.push_back({min(parent[u],  u), max(parent[u], u)});
		for(int v = 0; v < n; v++){
			if((k[u] + k[v]) * (abs(pos[u].first - pos[v].first) + abs(pos[u].second - pos[v].second)) < c[v]){
				c[v] = (k[u] + k[v]) * (abs(pos[u].first - pos[v].first) + abs(pos[u].second - pos[v].second));
				parent[v] = u;
			}
		}
	}
	cout << res << endl;
	sort(power_stations.begin(), power_stations.end());
	cout << power_stations.size() << endl;
	for(int i = 0; i < power_stations.size(); i++)
		cout << power_stations[i] + 1 << " ";
	cout << endl << connections.size() << endl;
	for(int i = 0; i < connections.size(); i++)
		cout << connections[i].first + 1 << " " << connections[i].second + 1 << endl;
}
