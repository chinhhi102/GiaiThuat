#include<bits/stdc++.h>
using namespace std;
#define int long long
void pri(int x){
	if(x){
		pri(x/2);
		cout<<x%2;
	}
}
#undef int
int main(int argc, char const *argv[]){
#define int long long
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//    freopen("Electric//00.in","r",stdin);
//    freopen("out.txt","w",stdout);
    int n;
    cin>>n;
	if(n)
		pri(n);
	else
		cout<<0;
    return 0;
}
