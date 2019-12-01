#include<bits/stdc++.h>
using namespace std;
#define int long long
#undef int
int main(){
#define int long long
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	map<int,int> m;
	int q,x;
	string s;
	cin>>q;
	while(q--){
		cin>>s>>x;
		if(s=="add")
			m[x]++;
		else if(s=="del")
			m[x]--;
		else{
			int total=0;
			vector<int> v;
			for(int i=0;i<20;i++)
				if((1<<i)&x)
					v.push_back(i);
			int cur=0;
			total+=(m[0]>0);
			for(int i=0;i<v.size();i++){
				cur|=(1<<v[i]);
				total+=(m[cur]>0);
			}
			cout<<total<<endl;
		}
	}
	return 0;
}
