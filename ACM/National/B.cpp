#include<bits/stdc++.h>
using namespace std;
#define int long long
#define MAX 1000010
struct Point{
	int x,y,z;
};
vector<int> Ox[MAX], Oy[MAX], Oz[MAX];
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
		pair<Point, Point> Break[m + 1];
		int x, y, z;
		for(int i = 1; i <= m; i++){
			cin >> x >> y >> z;
			nhan[i].x = x;
			nhan[i].y = y;
			nhan[i].z = z;
			Ox[x].push_back(i);
			Oy[y].push_back(i);
			Oz[z].push_back(i);
		}
		int nL = m;
		int last = 1, dem;
		for(int i = 1; i <= a; i++){
			dem = Ox[i].size();
			nL -= dem;
			if(dem == 1){
				int xx = Ox[i][0];
				Point A, B;
				A.x = last;
				if(nL == 0) B.x = a;
				else B.x = i;
				A.y = A.z = 1;
				B.y = b;
				B.z = c;		
				Break[xx] = {A, B};
				last = i + 1;
			}else if(dem != 0){
				
			}
			if(nL == 0) break;
		}
	}
}
