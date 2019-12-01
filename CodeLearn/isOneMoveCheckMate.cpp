#include<bits/stdc++.h>
using namespace std;
int Kx,Ky;
// path of Knight
int dx[]={-2,-1,1,2,-2,-1,1,2};
int dy[]={-1,-2,-2,-1,1,2,2,1};
bool isOneMoveCheckMate(std::vector<std::string> pos)
{
	int n=pos.size();
	int z=8;
	int board[z+1][z+1]={};
	bool xxx[z+1][z+1]={};
	int id=1;
	int x,y;
	for(auto mate:pos){
		y=mate[1]-'a'+1; // cot
		x=mate[2]-'0'; // hang
		if(mate[0]=='K'){
			Kx = x;
			Ky = y;
			for(int i=-1;i<=1;i++)
				for(int j=-1;j<=1;j++){
					if(x+i>=1 && x+i<=z && y+j>=1 && y+j<=z){
						board[x+i][y+j]++;
						xxx[x+i][y+j]=1;
					}
				}
		}else{
			switch(mate[0]){
				case 'k':{
					for(int i=-1;i<=1;i++)
						for(int j=-1;j<=1;j++){
							if(x+i>=1 && x+i<=z && y+j>=1 && y+j<=z){
								board[x+i][y+j]--;
							}
						}
					break;
				}
				case 'q':{
					for(int i=1;i<=z;i++){
						board[x][i]--;
						board[i][y]--;
					}
					for(int i=1;i<=z;i++){
						if((x+y-i)<=z && (x+y-i)>0)
							board[i][(x+y)-i]--;
						if((i-x+y)<=z && (i-x+y)>0)
							board[i][i-x+y]--;
					}
					break;
				}
				case 'r':{
					for(int i=1;i<=z;i++){
						board[x][i]--;
						board[i][y]--;
					}
					break;
				}
				case 'b':{
					for(int i=1;i<=z;i++){
						if((x+y-i)<=z && (x+y-i)>0)
							board[i][(x+y)-i]--;
						if((i-x+y)<=z && (i-x+y)>0)
							board[i][i-x+y]--;
					}
					break;
				}
				case 'n':{
					int nx,ny;
					for(int i=0;i<8;i++){
						nx=x+dx[i];
						ny=y+dy[i];
						if(nx<=z && nx>0 && ny<=z && ny>0)
							board[nx][ny]--;
					}
					break;
				}
			}
		}
	}
//	for(int i=1;i<=z;i++){
//		for(int j=1;j<=z;j++){
//			cout<<board[i][j]<<' ';
//		}
//		cout<<endl;
//	}
	for(auto mate:pos){
		if(mate[0]=='K')
			continue;
		y=mate[1]-'a'+1; // cot
		x=mate[2]-'0'; // hang
		switch(mate[0]){
			case 'k':{
				for(int i=-1;i<=1;i++)
					for(int j=-1;j<=1;j++){
						if(x+i>=1 && x+i<=z && y+j>=1 && y+j<=z){
							board[x+i][y+j]++;
						}
					}
				for(int i=-1;i<=1;i++)
					for(int j=-1;j<=1;j++){
						if(x+i>=1 && x+i<=z && y+j>=1 && y+j<=z){
							if(xxx[x+i][y+j])continue;
							for(int k=-1;k<=1;k++)
								for(int l=-1;l<=1;l++){
									if(x+i+k>=1 && x+i+k<=z && y+j+l>=1 && y+j+l<=z){
										board[x+i+k][y+j+l]--;
								}
							}
							bool check=true;
							for(int i=-1;i<=1;i++)
								for(int j=-1;j<=1;j++){
									if(x+i>=1 && x+i<=z && y+j>=1 && y+j<=z){
										if(board[Kx+i][Ky+j]>0)
											check=false;
								}
							}
							if(check)
								return true;
							for(int k=-1;k<=1;k++)
								for(int l=-1;l<=1;l++){
									if(x+i+k>=1 && x+i+k<=z && y+j+l>=1 && y+j+l<=z){
										board[x+i+k][y+j+l]++;
									}
								}
						}
					}
				for(int i=-1;i<=1;i++)
					for(int j=-1;j<=1;j++){
						if(x+i>=1 && x+i<=z && y+j>=1 && y+j<=z){
							board[x+i][y+j]--;
						}
					}
				break;
			}
			case 'q':{
				for(int i=1;i<=z;i++){
					board[x][i]++;
					board[i][y]++;
				}
				for(int i=1;i<=z;i++){
					if((x+y-i)<=z && (x+y-i)>0)
						board[i][(x+y)-i]++;
					if((i-x+y)<=z && (i-x+y)>0)
						board[i][i-x+y]++;
				}
				for(int k=1;k<=z;k++){
					if(xxx[x][k] && board[x][k]>0)
						continue;
					for(int i=1;i<=z;i++){
						board[x][i]--;
						board[i][k]--;
					}
					for(int i=1;i<=z;i++){
						if((x+k-i)<=z && (x+k-i)>0)
							board[i][(x+k)-i]--;
						if((i-x+k)<=z && (i-x+k)>0)
							board[i][i-x+k]--;
					}
					bool check=true;
					for(int i=-1;i<=1;i++)
						for(int j=-1;j<=1;j++){
							if(x+i>=1 && x+i<=z && y+j>=1 && y+j<=z){
								if(board[Kx+i][Ky+j]>0)
									check=false;
						}
					}
					if(check)
						return true;
					for(int i=1;i<=z;i++){
						board[x][i]++;
						board[i][k]++;
					}
					for(int i=1;i<=z;i++){
						if((x+k-i)<=z && (x+k-i)>0)
							board[i][(x+k)-i]++;
						if((i-x+k)<=z && (i-x+k)>0)
							board[i][i-x+k]++;
					}
				}
				for(int k=1;k<=z;k++){
					if(xxx[k][y] && board[k][y]>0)
						continue;
					for(int i=1;i<=z;i++){
						board[k][i]--;
						board[i][y]--;
					}
					for(int i=1;i<=z;i++){
						if((k+y-i)<=z && (k+y-i)>0)
							board[i][(k+y)-i]--;
						if((i-k+y)<=z && (i-k+y)>0)
							board[i][i-k+y]--;
					}		
					bool check=true;
					for(int i=-1;i<=1;i++)
						for(int j=-1;j<=1;j++){
							if(x+i>=1 && x+i<=z && y+j>=1 && y+j<=z){
								if(board[Kx+i][Ky+j]>0)
									check=false;
						}
					}
					if(check)
						return true;
					for(int i=1;i<=z;i++){
						board[k][i]++;
						board[i][y]++;
					}
					for(int i=1;i<=z;i++){
						if((k+y-i)<=z && (k+y-i)>0)
							board[i][(k+y)-i]++;
						if((i-k+y)<=z && (i-k+y)>0)
							board[i][i-k+y]++;
					}	
				}
				for(int k=1;k<=z;k++){
					int d=(x+y)-k;
					if(d<=z && d>0){
						if(xxx[k][d] && board[k][d]>0)
							continue;
						for(int i=1;i<=z;i++){
							board[k][i]--;
							board[i][d]--;
						}
						for(int i=1;i<=z;i++){
							if((k+d-i)<=z && (k+d-i)>0)
								board[i][(k+d)-i]--;
							if((i-k+d)<=z && (i-k+d)>0)
								board[i][i-k+d]--;
						}
						bool check=true;
						for(int i=-1;i<=1;i++)
							for(int j=-1;j<=1;j++){
								if(x+i>=1 && x+i<=z && y+j>=1 && y+j<=z){
									if(board[Kx+i][Ky+j]>0)
										check=false;
							}
						}
						if(check)
							return true;
						for(int i=1;i<=z;i++){
							board[k][i]++;
							board[i][d]++;
						}
						for(int i=1;i<=z;i++){
							if((k+d-i)<=z && (k+d-i)>0)
								board[i][(k+d)-i]++;
							if((i-k+d)<=z && (i-k+d)>0)
								board[i][i-k+d]++;
						}
					}
				}
				for(int k=1;k<=z;k++){
					int d=k-x+y;
					if(d<=z && d>0){
						if(xxx[k][d] && board[k][d]>0)
							continue;
						for(int i=1;i<=z;i++){
							board[k][i]--;
							board[i][d]--;
						}
						for(int i=1;i<=z;i++){
							if((k+d-i)<=z && (k+d-i)>0)
								board[i][(k+d)-i]--;
							if((i-k+d)<=z && (i-k+d)>0)
								board[i][i-k+d]--;
						}
						bool check=true;
						for(int i=-1;i<=1;i++)
							for(int j=-1;j<=1;j++){
								if(x+i>=1 && x+i<=z && y+j>=1 && y+j<=z){
									if(board[Kx+i][Ky+j]>0)
										check=false;
							}
						}
//						cout<<endl;for(int i=1;i<=z;i++){
//		for(int j=1;j<=z;j++)
//			cout<<board[i][j]<<' ';
//		cout<<endl;
//	}
						if(check)
							return true;
						for(int i=1;i<=z;i++){
							board[k][i]++;
							board[i][d]++;
						}
						for(int i=1;i<=z;i++){
							if((d+k-i)<=z && (d+k-i)>0)
								board[i][(k+d)-i]++;
							if((i-k+d)<=z && (i-k+d)>0)
								board[i][i-k+d]++;
						}
					}
				}
				for(int i=1;i<=z;i++){
					board[x][i]--;
					board[i][y]--;
				}
				for(int i=1;i<=z;i++){
					if((x+y-i)<=z && (x+y-i)>0)
						board[i][(x+y)-i]--;
					if((i-x+y)<=z && (i-x+y)>0)
						board[i][i-x+y]--;
				}
				break;
			}
			case 'r':{
				for(int i=1;i<=z;i++){
					board[x][i]++;
					board[i][y]++;
				}
				for(int k=1;k<=z;k++){
					if(xxx[x][k] && board[x][k]>0)
						continue;
					for(int i=1;i<=z;i++){
						board[x][i]--;
						board[i][k]--;
					}
					bool check=true;
					for(int i=-1;i<=1;i++)
						for(int j=-1;j<=1;j++){
							if(x+i>=1 && x+i<=z && y+j>=1 && y+j<=z){
								if(board[Kx+i][Ky+j]>0)
									check=false;
						}
					}
					if(check)
						return true;
					for(int i=1;i<=z;i++){
						board[x][i]++;
						board[i][k]++;
					}
				}
				for(int k=1;k<=z;k++){
					if(xxx[k][y] && board[k][y]>0)
						continue;
					for(int i=1;i<=z;i++){
						board[k][i]--;
						board[i][y]--;
					}
					bool check=true;
					for(int i=-1;i<=1;i++)
						for(int j=-1;j<=1;j++){
							if(Kx+i>=1 && Kx+i<=z && Ky+j>=1 && Ky+j<=z){
								if(board[Kx+i][Ky+j]>0)
									check=false;
							}
						}
					if(check)
						return true;
					for(int i=1;i<=z;i++){
						board[k][i]++;
						board[i][y]++;
					}
				}
				for(int i=1;i<=z;i++){
					board[x][i]--;
					board[i][y]--;
				}
				break;
			}
			case 'b':{
				for(int i=1;i<=z;i++){
					if((x+y-i)<=z && (x+y-i)>0)
						board[i][(x+y)-i]++;
					if((i-x+y)<=z && (i-x+y)>0)
						board[i][i-x+y]++;
				}
				for(int k=1;k<=z;k++){
					int d=(x+y)-k;
					if(d<=z && d>0){
						if(xxx[k][d] && board[k][d]>0)
							continue;
						for(int i=1;i<=z;i++){
							board[k][i]--;
							board[i][d]--;
						}
						for(int i=1;i<=z;i++){
							if((k+d-i)<=z && (k+d-i)>0)
								board[i][(k+d)-i]--;
							if((i-k+d)<=z && (i-k+d)>0)
								board[i][i-k+d]--;
						}
						bool check=true;
						for(int i=-1;i<=1;i++)
							for(int j=-1;j<=1;j++){
								if(x+i>=1 && x+i<=z && y+j>=1 && y+j<=z){
									if(board[Kx+i][Ky+j]>0)
										check=false;
							}
						}
						if(check)
							return true;
						for(int i=1;i<=z;i++){
							board[k][i]++;
							board[i][d]++;
						}
						for(int i=1;i<=z;i++){
							if((y+k-i)<=z && (y+k-i)>0)
								board[i][(k+d)-i]++;
							if((i-k+d)<=z && (i-k+d)>0)
								board[i][i-k+d]++;
						}
					}
				}
				for(int k=1;k<=z;k++){
					int d=k-x+y;
					if(d<=z && d>0){
						if(xxx[k][d] && board[k][d]>0)
							continue;
						for(int i=1;i<=z;i++){
							board[k][i]--;
							board[i][d]--;
						}
						for(int i=1;i<=z;i++){
							if((k+d-i)<=z && (k+d-i)>0)
								board[i][(k+d)-i]--;
							if((i-k+d)<=z && (i-k+d)>0)
								board[i][i-k+d]--;
						}
						bool check=true;
						for(int i=-1;i<=1;i++)
							for(int j=-1;j<=1;j++){
								if(x+i>=1 && x+i<=z && y+j>=1 && y+j<=z){
									if(board[Kx+i][Ky+j]>0)
										check=false;
							}
						}
						if(check)
							return true;
						for(int i=1;i<=z;i++){
							board[k][i]++;
							board[i][d]++;
						}
						for(int i=1;i<=z;i++){
							if((y+k-i)<=z && (y+k-i)>0)
								board[i][(k+d)-i]++;
							if((i-k+d)<=z && (i-k+d)>0)
								board[i][i-k+d]++;
						}
					}
				}
				for(int i=1;i<=z;i++){
					if((x+y-i)<=z && (x+y-i)>0)
						board[i][(x+y)-i]--;
					if((i-x+y)<=z && (i-x+y)>0)
						board[i][i-x+y]--;
				}
				break;
			}
			case 'n':{
				int nx,ny;
				for(int i=0;i<8;i++){
					nx=x+dx[i];
					ny=y+dy[i];
					if(nx<=z && nx>0 && ny<=z && ny>0)
						board[nx][ny]++;
				}
				for(int i=0;i<8;i++){
					nx=x+dx[i];
					ny=y+dy[i];
					if(nx<=z && nx>0 && ny<=z && ny>0){
						if(xxx[nx][ny] && board[nx][ny] > 0)
							continue;
						int nnx,nny;
						for(int i=0;i<8;i++){
							nnx=nx+dx[i];
							nny=ny+dy[i];
							if(nnx<=z && nnx>0 && nny<=z && nny>0)
								board[nnx][nny]--;
						}
						bool check=true;
						for(int i=-1;i<=1;i++)
							for(int j=-1;j<=1;j++){
								if(x+i>=1 && x+i<=z && y+j>=1 && y+j<=z){
									if(board[Kx+i][Ky+j]>0)
										check=false;
							}
						}
						if(check)
							return true;
						for(int i=0;i<8;i++){
							nnx=nx+dx[i];
							nny=ny+dy[i];
							if(nnx<=z && nnx>0 && nny<=z && nny>0)
								board[nnx][nny]++;
						}
					}
				}
				for(int i=0;i<8;i++){
					nx=x+dx[i];
					ny=y+dy[i];
					if(nx<=z && nx>0 && ny<=z && ny>0)
						board[nx][ny]--;
				}
				break;
			}
		}

	}
	return false;
}
int main(){
	int n;
	cin>>n;
	vector<string> s(n);
	for(int i=0;i<n;i++)
		cin>>s[i];
	cout<<(isOneMoveCheckMate(s)?"True":"False")<<endl;
}
/*
7
Ka8 na5 kc1 qd2 rg1 bd3 rg7
*/
