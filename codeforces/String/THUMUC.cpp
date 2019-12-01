#include "D:\\baiTapLapTrinh\competitive_programming.h"
void solve();

int main(){
	io;
	solve();
	return 0;
}

void solve(){
	string s;
	cin>>s;
	bool is=false;
	bool in=true;
	fora(i,0,s.size()){
		if(s[i]=='/'){
			in=true;
		}else{
			if(in){
				cout<<'/';
				in=false;
			}
			cout<<s[i];
			is=true;
		}
	}
	if(!is)
		cout<<'/';
}
