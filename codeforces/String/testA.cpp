#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,m,k,i,j,q,r,l,c;
	int a[1001];
	memset(a,0,sizeof(a));
	string s,t;
	cin>>n>>m>>q;
	cin>>s>>t;
	for(i=0;i<=n-m;i++)
	{
		if(s.substr(i,m)==t)
			a[i]=1;
	}
	while(q--)
	{
		c=0;
		cin>>r>>l;
		for(i=r-1;i<=l-m;i++)
		{
			if(a[i])
				c++;	
		}
		cout<<c<<endl;
	}
}
/*
8 3 1
abacabac
aba
3 7
*/
