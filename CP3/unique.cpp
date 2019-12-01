#include "D:\\baiTapLapTrinh\competitive_programming.h"
void solve();

int main(){
	io;
	solve();
	return 0;
}

void solve(){
	int a[]={1,2,2,2,4,3,2,2,1};
	vi v(a,a+9);
	sort(all(v));
	UNIQUE(v);
	fora(i,0,(int)v.size())
		printf("%d\n",v[i]);
}
