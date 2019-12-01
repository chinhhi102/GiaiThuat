#include "D:\\baiTapLapTrinh\competitive_programming.h"
void solve();

int main(){
	io;
	solve();
	return 0;
}

void solve(){
	int n,p;
	cin>>n>>p;
	int a[n];
	fora(i,0,n)
		cin>>a[i];
	sort(a,a+n);
	int total=0;
	fora(i,1,n){
		int least=p*(i+1);
		int be=a[i];
		total=max(total,least-be);
	}
	cout<<total+a[0]<<endl;
}
