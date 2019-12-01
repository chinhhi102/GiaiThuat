#include "D:\\baiTapLapTrinh\competitive_programming.h"
class FenwickTree{
	private:
		vi ft;
	public:
		FenwickTree(int n){
			ft.assign(n+1,0);
		}
		int rsq(int b){
			int sum=0;
			for(;b>0;b-=(b&(-b)))
				sum+=ft[b];
			return sum;
		}
		int rsq(int a,int b){
			return rsq(b)-(a==1?0:rsq(a-1));
		}
		void update(int k,int v){
			for(;k<ft.size();k+=(k&(-k)))
				ft[k]+=v;
		}
};
void solve();

int main(){
	io;
	solve();
	return 0;
}

void solve(){
	int arr[]={1,2,3,4,5,6,7,8,9};
	FenwickTree ft(10);
	fora(i,0,10)
		ft.update(i+1,arr[i]);
	cout<<ft.rsq(2,9);
}
