#include<bits/stdc++.h>
using namespace std;
#define MAXSIZE (1<<10)
int wall[MAXSIZE + 1][MAXSIZE + 1];
int num = 0;
void xuat(int k){
	for(int i = 1; i <= (1<<k); i++){
		for(int j = 1; j <= (1<<k); j++)
			cout << wall[i][j] << '\t';
		cout << endl;
	}
}

void cover(int x, int y, int s, int t){
	if(s == 2){
		num++;
		if(t != 1) wall[x][y] 		  = num;
		if(t != 2) wall[x][y + 1] 	  = num;
		if(t != 3) wall[x + 1][y] 	  = num;
		if(t != 4) wall[x + 1][y + 1] = num;
		return;
	}
	if(t == 1){
		cover(x, y + s/2, s/2, 3);
		cover(x + s/2, y, s/2, 2);
		cover(x + s/2, y + s/2, s/2, 1);
		cover(x + s/4, y + s/4, s/2, 1);
	}
	if(t == 2){
		cover(x, y, s/2, 4);
		cover(x + s/2, y, s/2, 2);
		cover(x + s/2, y + s/2, s/2, 1);
		cover(x + s/4, y + s/4, s/2, 2);
	}
	if(t == 3){
		cover(x, y, s/2, 4);
		cover(x, y + s/2, s/2, 3);
		cover(x + s/2, y + s/2, s/2, 1);
		cover(x + s/4, y + s/4, s/2, 3);
	}
	if(t == 4){
		cover(x, y, s/2, 4);
		cover(x + s/2, y, s/2, 2);
		cover(x, y + s/2, s/2, 3);
		cover(x + s/4, y + s/4, s/2, 4);
	}
}

int main(){
	int k;
	cout << "k = ";
	cin >> k;
	memset(wall, 0, sizeof wall);
	cover(1, 1, (1<<k), 2);
	xuat(k);
}
