#include "D:\\baiTapLapTrinh\competitive_programming.h"
void solve();

int main(){
	io;
	solve();
	return 0;
}

void solve(){
	int n=5,L[]={10,11,12,7,5},v=5;
	sort(L,L+n);
	printf("%d\n",binary_search(L,L+n,v));
}
