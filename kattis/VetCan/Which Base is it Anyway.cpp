#include "D:\\baiTapLapTrinh\competitive_programming.h"
void solve();

int main(){
	io;
	solve();
	return 0;
}

void solve(){
	int n;
	cin>>n;
	while(n--){
		int test_cases;
		int k;
		cin>>test_cases>>k;
		int tp=k;
		int a[2]={};
		bool f=true;
		int po=0;
		while(k){
			if(k%10>7)
				f=false;
			a[0]+=(k%10)*pow(8,po);
			a[1]+=(k%10)*pow(16,po);
			po++;
			k/=10;
		}
		cout<<test_cases<<' '<<(f?a[0]:0)<<' '<<tp<<' '<<a[1]<<endl;
	}
}
