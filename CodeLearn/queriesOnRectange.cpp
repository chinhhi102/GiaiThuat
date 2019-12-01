#include<bits/stdc++.h>
using namespace std;
std::vector<int> queriesOnRectange(int n, int m, std::vector<std::vector<int>> queries1, std::vector<std::vector<int>> queries2)
{
	vector<int> res;
	int nq1=queries1.size(),nq2=queries2.size();
	vector<vector<int>> sum(n+1,vector<int>(m+1,0)), dk(n+1,vector<int>(m+1,0));
	for(int i=0;i<nq1;i++){
		dk[queries1[i][0]][queries1[i][1]]++;
		dk[queries1[i][2]+((queries1[i][3]+1)==m)][((queries1[i][3]+1)==m)?0:queries1[i][3]+1]--;
	}
	int d=0;
//	cout<<endl;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			d+=dk[i][j];
//			cout<<d<<' ';
			sum[i+1][j+1]=sum[i][j+1]+sum[i+1][j]-sum[i][j]+d;
		}
//		cout<<endl;
	}
//	cout<<endl;
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=m;j++)
//			cout<<sum[i][j]<<' ';
//		cout<<endl;
//	}
	for(int i=0;i<nq2;i++){
		int r=sum[queries2[i][2]+1][queries2[i][3]+1]-sum[queries2[i][0]][queries2[i][3]+1]-sum[queries2[i][2]+1][queries2[i][1]]+sum[queries2[i][0]][queries2[i][1]];
		res.push_back(r);
	}
	return res;
}
int main(){
	int n,m;
	cin>>n>>m;
	int d;
	cin>>d;
	vector<vector<int>> queries1,queries2;
	for(int i=0;i<d;i++){
		vector<int> x(4);
		for(int j=0;j<4;j++)
			cin>>x[j];
		queries1.push_back(x);
	}
	cin>>d;
	for(int i=0;i<d;i++){
		vector<int> x(4);
		for(int j=0;j<4;j++)
			cin>>x[j];
		queries2.push_back(x);
	}
	vector<int> res = queriesOnRectange(n,m,queries1,queries2);
	for(int i=0;i<res.size();i++)
		cout<<res[i]<<' ';
}
/*
5 4
8
1 2 4 3
0 0 2 1
1 1 1 2
0 0 4 3
3 2 4 1
2 0 3 0
1 1 1 3
1 2 1 2
10
1 2 1 2
1 2 1 3
0 0 4 3
4 0 4 3
0 0 4 0
0 1 1 2
0 2 1 3
3 0 4 0
2 2 4 2
2 0 3 1
*/
