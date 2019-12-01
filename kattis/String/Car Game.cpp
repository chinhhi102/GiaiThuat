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

#define io ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
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
bool match(string s, string pat) {
    bool f1 = false;
    bool f2 = false;
    fora(i,0,s.size()){
        if(s[i]==pat[2]&&f2){
            return 1;
        }
        if(s[i]==pat[1]&&f1){
            f2=1;
        }
        if(s[i]==pat[0]){
            f1=1;
        }
    }
    return false;
}
int main(){
	io;
	int n, m;
    cin>>n>>m;
    vector<string> v(n);
    map<char, bool> ininput;
    for(char i='a';i<='z';i++){
        ininput[i] = 0;
    }
    fora(s,0,n){
        cin>>v[s];
        fora(i,0,v[s].size()){
            ininput[v[s][i]]=1;
        }
    }
    map<string,int> memo;
    for(int i=0;i<m;i++){
        string s;
        cin>>s;
        fora(j,0,s.size()){
            s[j]+=32;
        }
        if(!ininput[s[0]] || !ininput[s[1]] || !ininput[s[2]]) {
            cout << "No valid word" << endl;
            continue;
        }
        if(memo.count(s)>0&&memo[s]==-1){
            cout << "No valid word" << endl;
            continue;
        }
        if(memo.count(s)>0){
            cout << v[memo[s]] << endl;
            continue;
        }
        bool found=0;
        int idx=0;
        fora(j,0,v.size()){
            if(match(v[j],s)){
                found=1;
                break;
            }
            idx++;
        }
        if(found){
            memo[s]=idx;
            cout<<v[idx]<<endl;
        }else{
            memo[s]=-1;
            cout<< "No valid word" << endl;
        }
    }
	return 0;
}
