#include "D:\\baiTapLapTrinh\competitive_programming.h"
void solve();

int main(){
	io;
	solve();
	return 0;
}

void solve(){
	string a,b;
	cin>>a>>b;
	int d=max((int)a.size(),(int)b.size());
	int i=a.size()-1;
	int j=b.size()-1;
	bool f=0;
	string res="";
	while(i>=0||j>=0){
		if(i>=0&&j>=0){
			int d=(a[i]-'0')+(b[j]-'0')+f;
			res+=char((d%10)+'0');
			f=d>9;
		}else if(i>=0){
			int d=(a[i]-'0')+f;
			res+=char((d%10)+'0');
			f=d>9;
		}else{
			int d=(b[j]-'0')+f;
			res+=char((d%10)+'0');
			f=d>9;
		}
		i--;j--;
	}
	if(f)
		res+="1";
	cout<<(string(res.rbegin(),res.rend()))<<endl;
}
