#include "D:\\baiTapLapTrinh\competitive_programming.h"
void solve();
bool kt(int x){
	int a=1;
	bool b[10]={};
	b[x%10]=true;
	while(x/=10){
		if(b[x%10])continue;
		b[x%10]=true;
		a++;
		if(a>2)return false;
	}
	return true;
}
int main(){
	io;
	solve();
	return 0;
}

void solve(){
	int n;
	cin>>n;
	int x=n;
	int total=99;
	if(n<100){
		cout<<n;
		return;
	}
	if(n<1000){
		fora(i,100,n+1){
			if(kt(i)){
				cout<<i<<' ';
				total++;
			}	
		}
		cout<<total<<endl;
		return;
	}else{
		 
	}
	
}
