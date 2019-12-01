#include <bits/stdc++.h>
using namespace std;
int a[209];
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        for(int i=0;i<k;i++)cin>>a[i];
        int mx=0;
        for(int i=1;i<=n;i++){
            int v=1e9;
            for(int j=0;j<k;j++)
                v=min(v,abs(i-a[j])+1);
            mx=max(mx,v);
        }
        cout<<mx<<endl;
    }
}
