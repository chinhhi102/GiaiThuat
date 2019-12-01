#include<bits/stdc++.h>
using namespace std;
int dx[]={0,1,0,-1};
int dy[]={1,0,-1,0};
vector<vector<int>> a(4,vector<int>(4)),b(4,vector<int>(4));
map<vector<vector<int>>,int> m;
map<vector<vector<int>>,vector<vector<int>>> parent;
int d=0;
int xx=0;
bool check(vector<vector<int>> a, vector<vector<int>> b){
	for(int i=1;i<4;i++){
		for(int j=1;j<4;j++)
			if(a[i][j]!=b[i][j])
				return false;
	}
	return true;
}
void dfs(queue<vector<vector<int>>> &q){
	xx++;
	queue<vector<vector<int>>> nq;
//	for(int i=1;i<4;i++){
//		for(int j=1;j<4;j++)
//			cout<<a[i][j]<<' ';
//		cout<<endl;
//	}
	while(!q.empty()){
		vector<vector<int>> cur = q.front();
		q.pop();
		if(m[cur])
			continue;
		m[cur]=xx;
		if(check(cur,b)){
			cout<<m[cur]<<endl;
			while(!check(cur,a)){
				cout<<endl;
				for(int i=1;i<4;i++){
					for(int j=1;j<4;j++)
						cout<<cur[i][j]<<' ';
					cout<<endl;
				}
				cur=parent[cur];
			}
			exit(0);
		}
		int xx=m[cur]+1;
		int x,y;
		for(int i=1;i<4;i++)
			for(int j=1;j<4;j++)
				if(cur[i][j]==0){
					x=i;
					y=j;
				}
		for(int i=0;i<4;i++){
			int nx=x+dx[i];
			int ny=y+dy[i];
			if(nx<=3&&ny<=3&&nx>0&&ny>0){
				vector<vector<int>> pa = cur;
				swap(cur[x][y],cur[nx][ny]);
				if(!m.count(cur))
					nq.push(cur);
				if(!parent.count(cur))
					parent[cur]=pa;
				swap(cur[x][y],cur[nx][ny]);
			}
		}
	}
	q=nq;
}
int main(){
	int n=3;
	int di,dj;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
			if(a[i][j]==0)
				di=i,dj=j;
		}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			cin>>b[i][j];
	queue<vector<vector<int>>> q;
	q.push(a);
	while(!q.empty())
		dfs(q);
}
/*
4 8 7
2 6 0
5 3 1

1 2 3
8 0 4
7 6 5

3 1 4
7 8 5
2 0 6

1 2 3
8 0 4
7 6 5
*/
