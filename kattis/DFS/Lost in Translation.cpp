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

void solve1();
void solve2();
ll inf=(ll)1<<59;
struct node{
    vector<ll> neighbors;
    ll bestcon;
    ll bestval;
    ll parent;
};
void bfs(map<string,vector<pair<string,int>>>& lang,queue<string>& q,queue<string>& nq,map<string,bool>& sd,map<string,bool>& vis,ll& total,ll& work){
	unordered_map<string,int> value;
	value.clear();
	while(!q.empty()){
		string ori=q.front();
		q.pop();
		if(vis[ori])continue;
		vis[ori]=true;
		fora(i,0,lang[ori].size()){
			pair<string,int> p=lang[ori][i];
			if(sd[p.ff]>0){
				sd[p.ff]=false;
				total+=p.ss;
				value[p.ff]=p.ss;
				work++;
			}else{
				if(value[p.ff]!=0){
					if(p.ss<value[p.ff]){
						total=total-value[p.ff]+p.ss;
						value[p.ff]=p.ss;
					}
				}
			}
			nq.push(p.ff);
		}
	}
}
int main(){
	io;
	solve1();
	solve2();
	return 0;
}

void solve1(){
	vector<string> target;
	map<string,vector<pair<string,int>>> lang;
	map<string,bool> sd;
	map<string,bool> vis;
	int n,m;
	cin>>n>>m;
	target.resize(n);
	fora(i,0,n){
		cin>>target[i];
		sd[target[i]]=true;
	}
	fora(i,0,m){
		string l1,l2;
		int cost;
		cin>>l1>>l2>>cost;
		lang[l1].pb({l2,cost});
		lang[l2].pb({l1,cost});
	}
	queue<string> q;
	q.push("English");
	ll total=0,work=0;
	while(!q.empty()){
		queue<string> nq;
		bfs(lang,q,nq,sd,vis,total,work);
		q=nq;
	}
	if(work==n){
		cout<<total<<endl;
	}else
		cout<<"Impossible"<<endl;
}
/*-----------------------------------------------------------------*/
void solve2(){
	vector<node> nodes;
    node start;
    start.bestcon = 0;
    start.bestval = 0;
    start.parent = -1;
    nodes.push_back(start);
    ll n,m;
    cin>>n>>m;
    map<string,ll>to_num;
    to_num["English"]=0;
    for(ll i=1;i<=n;i++){
        string name;
        cin>>name;
        to_num[name]=i;
        node temp;
        temp.bestcon=inf;
        temp.bestval=inf;
        temp.parent=-1;
        nodes.push_back(temp);
    }
    vector<vector<ll>> adj;
    adj.resize(n+1,vector<ll>(n+1,inf));
    for(ll i=0;i<=n;i++){
        adj[i][i]=0;
    }
    for(ll i=0;i<m;i++){
        string s1, s2;
        ll dist;
        cin>>s1>>s2>>dist;
        nodes[to_num[s1]].neighbors.pb(to_num[s2]);
        nodes[to_num[s2]].neighbors.pb(to_num[s1]);
        adj[to_num[s1]][to_num[s2]]=dist;
        adj[to_num[s2]][to_num[s1]]=dist;
    }
    queue<ll> q;
    q.push(0);
    while(!q.empty()) {
        ll curr=q.front();
        q.pop();
        for(auto i:nodes[curr].neighbors){
            if(nodes[curr].bestcon+1<nodes[i].bestcon){
                nodes[i].bestcon=nodes[curr].bestcon+1;
                nodes[i].bestval=nodes[curr].bestval+adj[curr][i];
                nodes[i].parent=curr;
                q.push(i);
            }else if(nodes[curr].bestcon+1==nodes[i].bestcon){
                if(adj[i][curr]<=adj[i][nodes[i].parent]){
                    nodes[i].bestcon=nodes[curr].bestcon+1;
                    nodes[i].bestval=nodes[curr].bestval+adj[curr][i];
                    nodes[i].parent=curr;
                    q.push(i);
                }
            }
        }
    }
    ll total=0;
    for(ll i=1;i<nodes.size();i++){
        node curr=nodes[i];
        if(curr.bestcon>inf/2){
            cout<<"Impossible"<<endl;
            return;
        }
//        cout<<curr.parent<<" ";
        total+=adj[curr.parent][i];
    }
    cout<<total<<endl;
}
