#include<bits/stdc++.h>
using namespace std;
int main(){
	char grid[10][10];
	int dx[]={1,0,-1,0};
	int dy[]={0,1,0,-1};
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    for(int i=0;i<7;i++){
        gets(grid[i]);
    }
    int res=0;
    for(int i=0;i<7;i++){
        for(int j=0;j<7;j++){
            for(int d=0;d<4;d++){
                int nx=i+dx[d];
                int ny=j+dy[d];
                int nnx=nx+dx[d];
                int nny=ny+dy[d];
                if (0<=nnx && nnx<7 && 0<=nny && nny<7 && grid[i][j]=='o' && grid[nx][ny]=='o' && grid[nnx][nny]=='.')res++;
            }
        }
        printf("\n");
    }
    printf("%d\n",res);
}
