#include<bits/stdc++.h>
using namespace std;
#define int long long
#undef int
int main(int argc, char const *argv[]){
#define int long long
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//    freopen("Electric//00.in","r",stdin);
//    freopen("out.txt","w",stdout);
    int n,m;
    cin>>m>>n;
	int a[m+1][n+1];
	for(int i=1;i<=m;i++)
		for(int j=1;j<=n;j++){
			a[0][j]=a[i][0]=0;
			cin>>a[i][j];
			a[i][j]+=(a[i-1][j]>a[i][j-1])?a[i-1][j]:a[i][j-1];
	}
	cout<<a[m][n];
    return 0;
}
