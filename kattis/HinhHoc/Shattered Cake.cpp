#include "D:\\baiTapLapTrinh\competitive_programming.h"
void solve();

int main(){
	io;
	solve();
	return 0;
}

void solve(){
	int w;
	cin>>w;
	int n;
	cin>>n;
	int total=0;
	fora(i,0,n){
		int x,y;
		cin>>x>>y;
		total+=x*y;
	}
	cout<<total/w;
}
