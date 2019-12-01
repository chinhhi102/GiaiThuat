#include<bits/stdc++.h>
using namespace std;
int dx[]={-1,0,0,1}; // len -> trai -> phai -> xuong
int dy[]={0,-1,1,0};
int a[102][102];
int dem = 0;
void backtrack(int x, int y){ // xay dung nghiem vt co chi so x, y
	dem++;
	a[x][y] = 1;
	for(int k = 0; k < 4; k++){ // chay 4 huong len - trai - phai - xuong
		int nx = x + dx[k];
		int ny = y + dy[k];
		if(a[nx][ny] != 1)
			backtrack(nx, ny);
	}
}
int main(){
	int n, m, x, y;
	cin >> n >> m >> x >> y;
	
	memset(a, 0, sizeof a);
	for(int i = 0; i < n+2; i++) a[i][0] = a[i][m + 1] = 1; // tao bo tuong
	for(int i = 0; i < m+2; i++) a[0][i] = a[n + 1][i] = 1; // tao bo tuong
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++)
		 	cin >> a[i][j]; // nhap du lieu
	backtrack(x, y);
	cout << dem << endl;
}
/*
4 5 2 4
1 1 1 1 1 1 1
1 0 0 1 0 0 1
1 0 1 0 0 1 1
1 1 0 0 0 0 1
1 0 1 0 0 1 1
1 1 1 1 1 1 1
*/
