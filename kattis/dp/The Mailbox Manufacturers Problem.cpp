#include "D:\\baiTapLapTrinh\competitive_programming.h"
void solve();
int test_mailbox(int k,int a,int b);
const int MAX_VALUE=1e9;
int memo[11][101][101];
int main(){
	io;
	solve();
	return 0;
}

void solve(){
	int num_cases,k,m;
    memset(memo,-1,sizeof(memo));
    cin>>num_cases;
    while(num_cases--){
        cin>>k>>m;
        cout<<test_mailbox(k,0,m)<<endl;
    }
}
int test_mailbox(int k,int a,int b){
    if(k==0)
        return MAX_VALUE;
    if(k==1)
        return (b*(b+1))/2-(a*(a+1))/2;
    if(a==b)
        return 0;
    if(memo[k][a][b]==-1) {
        int res=MAX_VALUE;
        fora(i,a+1,b+1){
            res=min(res,i+max(test_mailbox(k-1,a,i-1),test_mailbox(k,i,b)));
        }
        memo[k][a][b]=res;
    }
    return memo[k][a][b];
}
