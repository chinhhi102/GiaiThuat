#include "D:\\baiTapLapTrinh\competitive_programming.h"
typedef pair<double,double> co;
#define xx first
#define yy second
void solve();
double hsg(co& A,co& B){
	return ((double)B.yy-A.yy)/((double)B.xx-A.xx);
}
int main(){
	io;
	solve();
	return 0;
}

void solve(){
	vector<co> v(3);
	fora(i,0,3){
		cin>>v[i].xx>>v[i].yy;
	}
	if(v[1].xx-v[0].xx==0&&v[0].xx-v[2].xx==0){
		cout<<"TOWARDS"<<endl;
		return;
	}
	if(hsg(v[0],v[1])==hsg(v[1],v[2])){
		cout<<"TOWARDS"<<endl;
	}else{
		
	}
}
