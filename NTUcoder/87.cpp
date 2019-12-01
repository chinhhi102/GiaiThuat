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
    int n;
    cin>>s>>n;
    for(int i=n-1;i>=0;i--)
		cout<<s[i];
    for(int i=s.size()-1;i>=n;i--)
		cout<<s[i];
    return 0;
}
