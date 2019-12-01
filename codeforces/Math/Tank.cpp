#include <bits/stdc++.h>
//#include "rail.h"
#define F first
#define S second
#define P push
#define pb push_back
#define MEM(dp,i) memset(dp,i,sizeof(dp))
#define W while
#define R return
#define C continue
#define SI size()
#define ll long long
#define ld long double
#define pll pair<ll,ll>
#define pii pair<int,int>
#define SF(x) scanf("%Id",&x)
#define SF2(x,y) scanf("%Id%Id",&x,&y)
#define SF3(x,y,z) scanf("%I64d%I64d%I64d",&x,&y,&z)
#define SF4(x,y,z,o) scanf("%I64d%I64d%I64d%I64d",&x,&y,&z,&o)
#define all(v) v.begin(),v.end()

using namespace std;
const long long INF = 1e16;
const long long MOD = 1e9+7;
const int MAX=200015;
int a[5006];
int dp[5006];
int pre[5006];
bool b[5006];
int n,k,v;
void pro(int x){
    if(x<0){x+=k;}
    if(x==0)R;
    b[pre[x]]=1;
    pro(x-(a[pre[x]]%k));
}
int main(){
    cin>>n>>k>>v;
    int sum=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        sum+=a[i];
    }
    if(sum<v){
        cout<<"NO";
        R 0;
    }
    dp[0]=1;
    int num=v%k;
    for(int i=1;i<=n;i++){
        for(int j=5000;j>=0;j--){
            if(a[i]%k==0)continue;
            if(dp[(a[i]+j)%k]==1)continue;
            if(dp[j]&&pre[j]!=i){
                dp[(a[i]+j)%k]=1;
                pre[(a[i]+j)%k]=i;
            }
        }
    }
    if(dp[num]==0){
        cout<<"NO";
        R 0;
    }
    cout<<"YES\n";
    if(num==0){
        cout<<1e5<<" "<<1<<" "<<2<<endl;
        for(int i=3;i<=n;i++)cout<<1e5<<" "<<i<<" "<<2<<endl;
        num=v/k;
        if(num==0)R 0;
        cout<<num<<" "<<2<<" "<<1<<endl;
        R 0;
    }
    pro(num);
    int s;
    for(int i=1;i<=n;i++){
        if(b[i]){
//            cout<<i<<" ";
            s=i;
        }
    }
    for(int i=1;i<=n;i++){
        if(i==s)continue;
        if(b[i]){
            cout<<1e5<<" "<<i<<" "<<s<<endl;
            a[s]+=a[i];
            a[i]=0;
        }
    }
    int to;
    if(s==1)to=2;
    else to=1;
    for(int i=1;i<=n;i++){
        if(i==s)continue;
        if(i==to)continue;
        if(b[i])continue;
        cout<<1e5<<" "<<i<<" "<<to<<endl;
        a[to]+=a[i];
        a[i]=0;
    }
//    cout<<'s';
    int x=v-a[s];
    x/=k;
    if(x==0)R 0;
    if(x<0){
        swap(to,s);
        x*=-1;
    }
    cout<<x<<" "<<to<<" "<<s;

}
