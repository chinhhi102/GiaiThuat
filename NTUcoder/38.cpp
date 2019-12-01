#include<bits/stdc++.h>
using namespace std;
#define ll long long
map<int,int> m;
ll res=0;int x,n;
int main(){
	scanf("%d",&n);
	while(n--){
		scanf("%d",&x);
		m[x]++;
	}
	for(map<int,int>::iterator i=m.begin();i!=m.end();i++)
	res+=1LL*i->second*(i->second-1)/2;
	printf("%d",res);
}
