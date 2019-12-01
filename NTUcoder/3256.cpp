#include<bits/stdc++.h>
using namespace std;
#define int long long
void res(int n){
	if(n<2)
		cout<<-1;
	else if(!(n%7))
		cout<<n/7;
	else cout<<((n%7==4||n%7==6)?n/7+2:n/7+1);
}
#undef int
int main(int argc, char const *argv[]){
#define int long long
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//    freopen("Electric//00.in","r",stdin);
//    freopen("out.txt","w",stdout);
    int n;
    cin>>n;
	int a[n];
	for(int i=0;i<n;i++)
		cin>>a[i];
	for(int i=0;i<n;i++)
		res(a[i]),cout<<endl;
    return 0;
}
