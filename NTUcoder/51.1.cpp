#include<bits/stdc++.h>
using namespace std;
bool a[102][102]={};
int dx[]={0,1,0,-1};
int dy[]={-1,0,1,0};
int d=0;
void backtracking(int y,int x){
	a[y][x]=0;
	d++;
	for(int i=0;i<4;i++){
		int nx=x+dx[i];
		int ny=y+dy[i];
		if(a[ny][nx]){
			backtracking(ny,nx);
		}
	}
}
int main(){
	int n,m,y,x;
	cin>>n>>m>>y>>x;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>a[i][j];
			a[i][j]=!a[i][j];
		}
	}
	backtracking(y,x);
	cout<<d<<endl;
}
