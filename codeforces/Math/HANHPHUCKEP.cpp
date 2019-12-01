#include "D:\\baiTapLapTrinh\competitive_programming.h"
void solve();
#define MAXSANG 300000000
int snt[MAXSANG+1];
int main(){
	io;
	solve();
	return 0;
}

void solve(){
    long i,j;
    int l,r;
    cin>>l>>r;
    for (i=1; i<=r; i++)
        snt[i]=1;
    snt[1]=0;
    i=2;
    while(i<=sqrt(r)){
        while(snt[i]==0)
            i++;
        for(j=2; j<=r/i;j++)
            snt[i*j]=0;
        i++;
    }
    int res=0;
	fora(i,l,r+1)
		if(snt[i]&&i%4==1){
			cout<<i<<' '<<res++<<endl;
		}
	cout<<res<<endl;
}
