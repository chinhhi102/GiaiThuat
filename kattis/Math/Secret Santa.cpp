#include "D:\\baiTapLapTrinh\competitive_programming.h"
void solve();

int main(){
	io;
	solve();
	return 0;
}

void solve(){
	long long int n;
    cin>>n;
	long double ans = 0.367879441171442;
    if(n<50){
        long long int f=1;
        long long int i;
        ans=1;
        for(i=1;i<=n;++i) {
            f*=i;
            if(i%2==0){
                ans+=1.0/f;
            }else{
                ans-=1.0/f;
            }
        }
    }
    fix(8)<<1-ans<<endl;
}
