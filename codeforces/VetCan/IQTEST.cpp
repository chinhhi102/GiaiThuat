#include "D:\\baiTapLapTrinh\competitive_programming.h"
void solve();
int dx[]={0,1,0,1};
int dy[]={0,0,1,1};
int main(){
	io;
	solve();
	return 0;
}

void solve(){
	string s[4];
	fora(i,0,4)
		cin>>s[i];
	fora(i,0,3){
		fora(j,0,3){
			int w=0,b=0;
			fora(k,0,4){
				if(s[i+dx[k]][j+dy[k]]=='.')
					w++;
				else
					b++;
			}
			if(w>=3||b>=3){
				cout<<"YES"<<endl;
				return;
			}
		}
	}
	cout<<"NO"<<endl;
}
