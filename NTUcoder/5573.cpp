#include<bits/stdc++.h>
using namespace std;
int main(){
    int id=1,len=0;
    map<int,int>m;
    string s;
    cin>>s;
    s='0'+s;
    for(int i=1;i<s.size();i++){
        if(m[s[i]]>=id){
            len=max(len,i-id);
            id=m[s[i]]+1;
        }
    m[s[i]]=i;
    }
    cout<<max(len,(int)s.size()-id);
}
