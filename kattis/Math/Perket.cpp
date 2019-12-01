#include <bits/stdc++.h>
using namespace std;
#define ll long long
vector<bool> get_use(int i,int n){
    vector<bool>v(n,0);
    int count=0;
    while(i>0){
        if(i%2)v[count]=true;
        count++;
        i/=2;
    }
    return v;
}
ll calculate(vector<pair<ll, ll> >v, vector<bool>b) {
    ll sour=1;
    ll bitter=0;
    for(int i=0;i<v.size();i++) if(b[i]){
            sour*=v[i].first;
            bitter+=v[i].second;
        }
    return abs(bitter-sour);
}
int main(){
    int n;
    cin>>n;
    vector<pair<ll,ll> >v;
    for(int i=0;i<n;i++){
        pair<ll,ll>p;
        cin>>p.first>>p.second;
        v.push_back(p);
    }
    long long res = 1000000001;
    for(int i=1;i<pow(2,n);i++){res=min(calculate(v,get_use(i,n)),res);}
    cout<<res<<endl;
}
