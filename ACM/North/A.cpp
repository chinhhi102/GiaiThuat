#include<bits/stdc++.h>
using namespace std;
double calc_Dist(pair<int,int> x, pair<int,int> y){
	return sqrtl((x.first - y.first)*(x.first - y.first) + (x.second - y.second)*(x.second - y.second));
}
bool cmp(pair<double,pair<int,int>> x, pair<double,pair<int,int>> y){
	return x.first > y.first;
}
double calc_S(double a, double b, double c){
	double p = 0.5*(a+b+c);
	return sqrtl(p*(p-a)*(p-b)*(p-c));
}
int main(){
	int n;
	cin >> n;
	vector<pair<int,int>> points(n);
	for(int i = 0; i < n; i++){
		cin >> points[i].first >> points[i].second;
	}
	double dist[n][n];
	double maxn,minn;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			dist[j][i] = dist[i][j] = calc_Dist(points[i], points[j]);
		}
	}
	int k = 2;
	double res = 0.0;
	for(int i = 0; i < n; i++){
		for(int j = i + 1; j < n; j++){
			while(k + 1 < n && calc_S(dist[i][j], dist[i][k], dist[j][k]) <= calc_S(dist[i][j], dist[i][k + 1], dist[j][k + 1]))
				k++;
			res = max(res, calc_S(dist[i][j], dist[i][k], dist[j][k]));
		}
	}
	cout << fixed << setprecision(1) << res;
}
/*
6
0 0
0 10
5 15
12 12
15 5
10 0
4
0 0
0 10
12 12
10 0
*/
