#ifndef competitive_programming_H
#define competitive_programming_H
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
#define UNIQUE(c) (c).resize(unique(all(c))-(c).begin())
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
#endif
void solve();

#include<bits/stdc++.h>
using namespace std;
int fin(string s,int st,int& se){
    int best=0;
    int richness=0;
    vector<int> v(26);
    for(int i=st;i<s.size();i++){
        if(v[s[i]-'A']==0){
            richness++;
        }else if(v[s[i]-'A']==1){
            richness--;
        }
        if(richness>best){
            best=richness;
            se=i+1;
        }
        v[s[i]-'A']++;
    }
    return best;
}
int main(){
	io;
	solve();
	return 0;
}

void solve(){
	string s;
    cin>>s;
    int sz=s.size();
    int best=0;
    string res="";
    for(int i=0;i<sz;i++){
        int se=i;
        int sum=fin(s,i,se);
        string tmp=string(s.begin()+i,s.begin()+se);
        if(sum>best){
            best=sum;
            res=tmp;
        }else if(sum==best){
            if(res.compare(tmp)>0)
                res=tmp;
        }
    }
    cout<<res<<endl;
}
/*
ZYXWVUTSRQPONMLKJIHGFEDCBAZYXWVUTSRQPONMLKJIHGFEDCBA
*/
