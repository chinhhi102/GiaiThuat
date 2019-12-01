#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    long long res=0;
    int n,x;
    map<int,int> m[3];
    cin>>n;
    for(int i=0;i<3;i++)
    for(int j=0;j<n;j++)cin>>x,m[i][x]++;
    for(map<int,int>::iterator i=m[0].begin();i!=m[0].end();i++)res+=1LL*i->second*m[1][i->first]*m[2][i->first];
    cout<<res;
}
