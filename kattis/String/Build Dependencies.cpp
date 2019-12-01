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
//#include <tuple>
#include <ctype.h>
#include <stack>
#include <iterator>
#include <complex>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <functional>
#include <time.h>
//#include <unordered_map>
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
void split(vector<string>& ans, string& s) {
    ans.pb("");
    fora(i,0,s.size()){
        if(s[i] == ' ') {
            ans.pb("");
        }
        else {
            ans.back().pb(s[i	]);
        }
    }
}

int main(){
	io;
	int n;
	cin>>n;
	cin.ignore();
//	map<string,vector<string> > depen;
//	map<string,bool> kt;
	vector<string> rev;
    map<string,int> cnv;
    vector<vector<int> > adj(n);
	fora(i,0,n){
		string line;
		getline(cin,line);
		vector<string> v;
		split(v, line);
		v[0].pop_back();
//		isdepen.resize(isdepen.size()-1);
//		cout<<isdepen;
		fora(i,0,v.size()) {
            if(cnv.count(v[i]) == 0) {
                cnv[v[i]] = rev.size();
                rev.pb(v[i]);
            }
        }
		int n1=cnv[v[0]];
        fora(i,1,v.size()){
            adj[cnv[v[i]]].pb(n1);
        }
	}
	string start;
	cin>>start;
	int startidx = cnv[start];
	vector<int> deg(n,0);
    fora(i,0,n){
        fora(j,0,adj[i].size()){
            deg[adj[i][j]]++;
        }
    }
    queue<int> zeroin;
    fora(i,0,n){
        if(deg[i]==0&&i!=startidx){
            zeroin.push(i);
        }
    }
	while(!zeroin.empty()) {
        int curr = zeroin.front();
        zeroin.pop();
        fora(next,0,adj[curr].size()){
            deg[adj[curr][next]]--;
            if(deg[adj[curr][next]]==0&&adj[curr][next]!=startidx) {
                zeroin.push(adj[curr][next]);
            }
        }
    }
    zeroin.push(startidx);
    while(!zeroin.empty()) {
        int curr = zeroin.front();
        zeroin.pop();
        cout << rev[curr] << endl;
        fora(next,0,adj[curr].size()){
            deg[adj[curr][next]]--;
            if(deg[adj[curr][next]]==0) {
                zeroin.push(adj[curr][next]);
            }
        }
    }
	return 0;
}
