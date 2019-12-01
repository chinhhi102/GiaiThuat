#include<bits/stdc++.h>
using namespace std;
#define int long long
#undef int
int main(int argc, char const *argv[]){
#define int long long
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//    freopen("Electric//00.in","r",stdin);
//    freopen("out.txt","w",stdout);
    map<int,int> M;
	int n,res=0,x;
	cin>>n;
	while(n--)
		cin>>x,M[x]++;
	for(map<int,int>::iterator i=M.begin();i!=M.end();i++)
		res+=i->second>5?i->second-5:0;
	cout<<res+M.size()*100;
	return 0;
}

