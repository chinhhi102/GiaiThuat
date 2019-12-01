#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,x;
	map<int,int>m;
	vector<int>v;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&x);m[x]++;
		if(m[x]==3){
			v.push_back(x);
			m[x]=0;
		}
	}
	printf("%d\n",v.size());
	for(int i=0;i<v.size();i++)printf("%d ",v[i]);
}
