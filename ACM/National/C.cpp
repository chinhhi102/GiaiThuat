#include<bits/stdc++.h>
using namespace std;
#define int long long
struct Point{
	int x,y,z;
};
bool checkContain(pair<Point,Point> a, Point b){
	return (a.first.x <= b.x && b.x <= a.second.x) && (a.first.y <= b.y && b.y <= a.second.y) && (a.first.z <= b.z && b.z <= a.second.z);
}
bool checkCut(pair<Point, Point> a, pair<Point, Point> b){
	if((b.first.z <= a.first.z && a.first.z <= b.second.z) || (b.first.z <= a.second.z && a.second.z <= b.second.z)){
		if((b.first.y <= a.first.y && a.first.y <= b.second.y) || (b.first.y <= a.second.y && a.second.y <= b.second.y)){
			if((b.first.x <= a.first.x && a.first.x <= b.second.x) || (b.first.x <= a.second.x && a.second.x <= b.second.x))
				return true;
		}
	}
	if((a.first.z <= b.first.z && b.first.z <= a.second.z) || (a.first.z <= b.second.z && b.second.z <= a.second.z)){
		if((a.first.y <= b.first.y && b.first.y <= a.second.y) || (a.first.y <= b.second.y && b.second.y <= a.second.y)){
			if((a.first.x <= b.first.x && b.first.x <= a.second.x) || (a.first.x <= b.second.x && b.second.x <= a.second.x))
				return true;
		}
	}
	return false;
}
#undef int
int main(){
#define int long long
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int a, b, c, m;
	while(cin >> a && a != -1){
		cin >> b >> c >> m;
		Point nhan[m + 1];
		int V1 = a*b*c, V2 = 0;
		for(int i = 1; i <= m; i++){
			cin >> nhan[i].x >> nhan[i].y >> nhan[i].z;
		}
		pair<Point, Point> Break[m + 1];
		bool correct = true;
		for(int i = 1; i <= m; i++){
			cin >> Break[i].first.x >> Break[i].first.y >> Break[i].first.z;
			cin >> Break[i].second.x >> Break[i].second.y >> Break[i].second.z;
			if(Break[i].second.x < Break[i].first.x || Break[i].second.y < Break[i].first.y || Break[i].second.z < Break[i].first.z)
				correct = false;
			if(Break[i].first.x < 1 || Break[i].first.x > a)
				correct = false;
			if(Break[i].first.y < 1 || Break[i].first.y > b)
				correct = false;
			if(Break[i].first.z < 1 || Break[i].first.z > c)
				correct = false;
			if(Break[i].second.x < 1 || Break[i].second.x > a)
				correct = false;
			if(Break[i].second.y < 1 || Break[i].second.y > b)
				correct = false;
			if(Break[i].second.z < 1 || Break[i].second.z > c)
				correct = false;
			V2 += (Break[i].second.x - Break[i].first.x + 1) * (Break[i].second.y - Break[i].first.y + 1) * (Break[i].second.z - Break[i].first.z + 1);
		}
		if(V1 != V2 || !correct){
			cout << "NO" << endl;
			continue;
		}
		correct = true;
		for(int i = 1; i <= m; i++){
			if(!checkContain(Break[i], nhan[i])){
				correct = false;
				break;
			}
		}
		if(!correct){
			cout << "NO" << endl;
			continue;
		}
		correct = true;
		for(int i = 1; i < m; i++){
			for(int j = i + 1; j <= m; j++){
				if(checkCut(Break[i], Break[j])){
					correct = false;
					break;
				}
			}
			if(correct == false){
				break;
			}
		}
		cout << (correct ? "YES" : "NO") << endl;
	}
}
/*
5 5 5 2
5 1 1
4 4 4
1 1 1 5 5 2
1 1 2 5 5 4
5 5 5 1
3 3 3
1 1 1 5 5 6
-1
*/
