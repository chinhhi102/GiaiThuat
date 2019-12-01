#include<bits/stdc++.h>
using namespace std;
#define int long long
#undef int
int main(int argc, char const *argv[]){
#define int long long
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//    freopen("Electric//00.in","r",stdin);
//    freopen("out.txt","w",stdout);
    int n,m,a,b;
    cin>>n>>m;
    for(int a=1;a<n-1;a++)
    	for(int b=1;b<n-a;b++)
    		if((n-b-a)%3==0&&a*5+b*3+(n-b-a)/3==m){
        		cout<<a<<' '<<b<<' '<<n-b-a;
        		return 0;
    		}cout<<-1;
	return 0;
}

