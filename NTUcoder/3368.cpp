#include<bits/stdc++.h>
using namespace std;
#define int long long
int sum(string s){
	int m(0);
	for(int i=0;i<s.size();i++)
		m+=s[i]-'0';
	return m;
}
#undef int
int main(int argc, char const *argv[]){
#define int long long
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//    freopen("Electric//00.in","r",stdin);
//    freopen("out.txt","w",stdout);
    string ch;
    cin>>ch;
    cout<<sum(ch);
    return 0;
}
