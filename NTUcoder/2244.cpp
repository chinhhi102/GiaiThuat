#include<bits/stdc++.h>
using namespace std;
#define int long long
#undef int
int main(int argc, char const *argv[]){
#define int long long
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//    freopen("Electric//00.in","r",stdin);
//    freopen("out.txt","w",stdout);
    float n;
	int m,d=0;
	cin>>n>>m;
 	while(n<m){
 		n=round(n*1.1);
 		d++;
	}
	cout<<d;
	return 0;
}

