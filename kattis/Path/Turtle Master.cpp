#include <bits/stdc++.h>
using namespace std;
int main(){
	int dx[]={-1,0,1,0};// up - right - down - left
	int dy[]={0,1,0,-1};
	string grid[8];
	for(int i=0;i<8;i++)
		cin>>grid[i];
	string fac;
	cin>>fac;
	int sx=7,sy=0,dr=1;
	bool isBug=0;
	for(int i=0;i<fac.size();i++){
		if(isBug)break;
		if(fac[i]=='L')
			dr=(dr+4-1)%4;
		else if(fac[i]=='R')
			dr=(dr+1)%4;
		else if(fac[i]=='F'){
			sx+=dx[dr];
			sy+=dy[dr];
			if(sx<0||sy<0||sx>7||sy>7||grid[sx][sy]=='I'||grid[sx][sy]=='C'){
				isBug=1;
				break;
			}
		}else{
			int curx=sx,cury=sy;
			curx+=dx[dr];
			cury+=dy[dr];
			isBug=(curx<0||cury<0||curx>7||cury>7||grid[curx][cury]=='C'||grid[curx][cury]=='.');
			if(!isBug)
				grid[curx][cury]='.';
		}
	}
	cout<<((isBug||grid[sx][sy]!='D')?"Bug!":"Diamond!");
}
