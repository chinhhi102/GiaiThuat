#include "D:\\baiTapLapTrinh\competitive_programming.h"
void solve();

int main(){
	io;
	solve();
	return 0;
}

void solve(){
	int p[20],N=5;
	fora(i,0,N)p[i]=i;
	for(int i=0;i<(1<<N);i++){
		fora(j,0,N)
			if(i&(1<<j))
				printf("%d ",p[j]);
			printf("\n");
	}
}
