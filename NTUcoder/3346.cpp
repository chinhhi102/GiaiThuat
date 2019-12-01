#include<bits/stdc++.h>
using namespace std;
#define int long long
#undef int
int main(int argc, char const *argv[]){
#define int long long
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//    freopen("Electric//00.in","r",stdin);
//    freopen("out.txt","w",stdout);
    int a,b,j,res=0;
    cin>>a>>b;
    while(a<=b){
        while(a/1000!=a/10%10+a%10*10)
			a++;
        for(j=2;j<=sqrt(a);j++)
			if(a%j==0)break;
        if(j>sqrt(a))
			res++;
        a+=100;
    }
    cout<<res;
	return 0;
}

