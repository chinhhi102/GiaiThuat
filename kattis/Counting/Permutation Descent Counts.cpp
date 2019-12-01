#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include <string.h>
#define MAGIC_MODULUS	(1001113)
typedef unsigned long DWORD;
#define MAX_ORDER	100
#define NOT_YET_SET (0xffffffff)
char inbuf[256];
DWORD des[MAX_ORDER+1][MAX_ORDER];
void InitDes(void){
	int i, j;
	for(i = 0; i <= MAX_ORDER ; i++) {
		for(j = 0; j < MAX_ORDER ; j++) {
			des[i][j] = NOT_YET_SET;
		}
	}
	for(i = 1; i <= MAX_ORDER ; i++) {
		des[i][0] = 1;
		des[i][i-1] = 1;
	}
}
DWORD desc(int n, int v){
	if(des[n][v] != NOT_YET_SET) {
		return des[n][v];
	}
	des[n][v] = (((v + 1)) * desc(n-1,v) + ((n - v)) * desc(n-1, v-1)) % MAGIC_MODULUS;
	return des[n][v];
}
int main(){
	int p,k,n,v;
	DWORD res;
	scanf("%d", &p);
	InitDes();
	while(p--){
		scanf("%d %d %d", &k, &n, &v);
		res = desc(n, v);
		printf("%d %lu\n", k, res);
	}
	return 0;
}
