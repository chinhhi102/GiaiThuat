#include "D:\\baiTapLapTrinh\competitive_programming.h"
void solve();

int main(){
	io;
	solve();
	return 0;
}

void solve(){
	string s="1.AnhLaCuaEm 2.AnhKhongLaCuaEm";
	char* line=new char [s.size()+1];
	strcpy(line,s.c_str());
	char *p=strtok(line," ");
	while(p!=0){
		cout<<p<<endl;
		p=strtok(NULL," ");
	}
}
