#include<bits/stdc++.h>
using namespace std;
int main(){
    int id=0;
    string s,x="hello";
    cin>>s;
    for(int i=0;i<s.size();i++) s[i]-x[id]?id:id++;
    printf(id==5?"YES":"NO");
    return 0;
}
    
