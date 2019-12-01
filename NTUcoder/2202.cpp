#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    string s;
    int q,lim;
    long long a,b;
    cin>>s>>q;
    lim=s.size();
    s=s[lim-1]+s;
    while(q--){
        cin>>a>>b;
        printf((s[a%lim]==s[b%lim])?"Yes\n":"No\n");
    }
}
