#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	string s;
	while(getline(cin,s)){
		bool f=0;
		queue<int> q;
		for(int i=0;i<s.size();i++){
			if(s[i]=='u'||s[i]=='e'||s[i]=='o'||s[i]=='a'||s[i]=='i'||s[i]=='y'){
				while(i<s.size()&&s[i]!=' ')
					cout<<s[i++];
				if(f)
					while(!q.empty())
						cout<<s[q.front()],q.pop();
				else
					cout<<'y';
				cout<<"ay ";
				f=0;
			}else q.push(i),f=1;
		}
		cout<<endl;
	}
}
