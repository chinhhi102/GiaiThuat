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
	fora(dem,0,n){
		string s;
		cin>>s;
		int m=0,k;
		fora(i,0,101){
			if(i*i>=s.size()){
				m=i*i;
				k=i;
				break;
			}
		}
		s.resize(m,'*');
		string res="";
		res.resize(m,'*');
		fora(i,0,s.size()){
			res[(i%k)*k+(k-i/k-1)]=s[i];
		}
		fora(i,0,res.size()){
			if(res[i]=='*')
				res.erase(i--,1)) 
		}
		cout<<res<<endl;
	}
}
