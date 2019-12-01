#include<bits/stdc++.h>
using namespace std;
#define int long long
#undef int
int main(int argc, char const *argv[]){
#define int long long
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//    freopen("Electric//00.in","r",stdin);
//    freopen("out.txt","w",stdout);
    int h,m,s;
    cin>>h>>m>>s;s++;
    if(!(s-60)){
        m++;
        s=0;
        if(!(m-60)){
            m=0;
            h++;
            if(!(h-24))
                h=0;
        }
    }
    cout<<h<<' '<<m<<' '<<s;
    return 0;
}
