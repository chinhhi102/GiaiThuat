#include<bits/stdc++.h>
using namespace std;
#define int long long
#undef int
int main(int argc, char const *argv[]){
#define int long long
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//    freopen("Electric//00.in","r",stdin);
//    freopen("out.txt","w",stdout);
    string s;
    getline(cin,s);
    set<char> m;
    for(int i=0;i<s.size();i++)
		m.insert(s[i]);
	cout<<m.size();
	return 0;
}

