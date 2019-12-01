#include "D:\\baiTapLapTrinh\competitive_programming.h"
typedef pair<int,int> co;
#define xx first
#define yy second
void solve();
double Striangle(co& A,co& B,co& C);
double hight(co& M,co& A,co& B);
double dis(co& x,co& y);
int main(){
	io;
	solve();
	return 0;
}

void solve(){
	int n;
	cin>>n;
	fora(i,0,n){
		int m;
		cin>>m;
		double total=0;
		vector<co> a;
		fora(i,0,m){
			int x,y;
			cin>>x>>y;
			a.pb({x,y});
		}
		fora(i,2,m){
			total+=Striangle(a[0],a[i],a[i-1]);
//			cout<<total<<endl;
		}
		cout<<total<<endl;
	}
}
double Striangle(co& A,co& B,co& C){
	double S;
	S=(1.0/2)*(dis(B,C)*hight(A,B,C));
	return S;
}
double dis(co& x,co& y){
	return sqrt((x.xx-y.xx)*1.0*(x.xx-y.xx)+(x.yy-y.yy)*1.0*(x.yy-y.yy));
}
double hight(co& M,co& A,co& B){
	return double((1.0*abs(1.0*(A.yy-B.yy)*M.xx+(B.xx-A.xx)*M.yy+(B.yy*A.xx-B.xx*A.yy)))/(sqrt((1.0*(A.yy-B.yy)*(A.yy-B.yy))+(B.xx-A.xx)*(B.xx-A.xx))));
}
