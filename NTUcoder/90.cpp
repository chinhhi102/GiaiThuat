#include<bits/stdc++.h>
using namespace std;
int main(){
    string s;cin>>s;
    int k;
    scanf("%d",&k);
    for(int i=0;i<s.size();i++)printf("%c",s[i]-k+(s[i]-k<'a')*26);
}
