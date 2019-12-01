#include <map>
#include <set>
#include <queue>
#include <cmath>
#include <vector>
#include <cstdio>
#include <bitset>
#include <cstring>
#include <cstdlib>
#include <complex>
#include <iostream>
#include <algorithm>
#include <math.h>
#include <iomanip>
#include <list>
#include <tuple>
#include <ctype.h>
#include <stack>
#include <iterator>
#include <complex>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <functional>
#include <time.h>
#include <unordered_map>
#include <unordered_set>
#include <functional>
using namespace std;

#define io ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define fora(i,a,b) for(int i=a;i<b;i++)
#define fors(i,a,b) for(int i=a-1;i>=b;i--)
#define men(a) menset(a,0,sizeof(a))
#define sc(x) scanf("%d",&x)
#define scll(x) scanf("%lld",&x)
#define c1(a) cin>>a
#define c2(a,b) cin>>a>>b
#define c3(a,b,c) cin>>a>>b>>c
#define pb push_back
#define ff first
#define ss second
#define all(x) (x).begin(), (x).end()
#define M_PI 3.14159265358979323846
#define INF 1000000000000000000
#define fix(x) cout<<fixed<<setprecision(x)
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pi;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<bool> vb;
typedef vector<vector<int> > vvi;
typedef map<int,int> mi;
typedef map<long,long> mll;

typedef queue<pair<int,int>> q;
typedef vector<vector<char>> vvc;

int dx[]={0,1,0,-1};
int dy[]={1,0,-1,0};
int n,m;
vector<pair<int,int> > exi;
void solve();
void check(vvc& v,q& guys);
void bfs(vvc& v,q& oq,q& nq,bool p);
int main(){
    io;
    solve();
    return 0;
}
void bfs(vvc& v,q& oq,q& nq,bool p){
    while(!oq.empty()){
        int currx=oq.front().ff;
        int curry=oq.front().ss;
        oq.pop();
        if(p){
            fora(i,0,4){
                if(currx+dx[i]>=1&&currx+dx[i]<=n&&curry+dy[i]>=1&&curry+dy[i]<=m){
                    if(v[currx+dx[i]][curry+dy[i]]=='.'||v[currx+dx[i]][curry+dy[i]]=='@'){
                        v[currx+dx[i]][curry+dy[i]]='*';
                        nq.push({currx+dx[i],curry+dy[i]});
                    }
                }
            }
        }else{
            fora(i,0,4){
                if(currx+dx[i]>=0&&currx+dx[i]<=n+1&&curry+dy[i]>=0&&curry+dy[i]<=m+1){
                    if(v[currx+dx[i]][curry+dy[i]]=='.'){
                        v[currx+dx[i]][curry+dy[i]]='@';
                        nq.push({currx+dx[i],curry+dy[i]});
                    }
                }
            }
        }
    }
}
void check(vvc& v,q& guys){
    q newguys;
    while(!guys.empty()){
        pair<int,int> i;
        i=guys.front();
        guys.pop();
        if(v[i.ff][i.ss]!='*')
            newguys.push(i);
    }
    guys=newguys;
}
void solve(){
    int t;
    cin>>t;
    while(t--){
        cin>>m>>n;
        vvc v(n+2,vector<char> (m+2,'.'));
        q guys;
        q fire;
        fora(i,1,n+1){
            fora(j,1,m+1){
                cin>>v[i][j];
                if(v[i][j]=='@')
                    guys.push({i,j});
                if(v[i][j]=='*')
                    fire.push({i,j});
            }
        }
        bool work=false;
        int time=0;
        while(!guys.empty()||!fire.empty()){
            q newguys;
            q newfire;
            bfs(v,guys,newguys,false);
            bfs(v,fire,newfire,true);
            fora(i,0,n+2)
                if(v[i][0]=='@'||v[i][m+1]=='@')work=true;
            fora(i,0,m+2)
                if(v[0][i]=='@'||v[n+1][i]=='@')work=true;
            check(v,newguys);
            guys=newguys;
            fire=newfire;
            time++;
            if(work)break;
        }
        if(work)
            cout<<time<<endl;
        else
            cout<<"IMPOSSIBLE"<<endl;
    }
}
