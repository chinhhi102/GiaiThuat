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
#define all(x) (x).begin(), (x).end()
#define ss second
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
ll readint(){
    char r;
    bool start=0,neg=0;
    ll ret=0;
    while(1){
        r=getchar();
        if((r-'0'<0 || r-'0'>9) && r!='-' && !start){
            continue;
        }
        if((r-'0'<0 || r-'0'>9) && r!='-' && start){
            break;
        }
        if(start)ret*=10;
        start=true;
        if(r=='-')neg=true;
        else ret+=r-'0';
    }
    if(!neg) return ret;
    else return -ret;
}
int main(){
	io;
	int n, m;
    cin >> n >> m;

    string s1, s2;
    cin >> s1 >> s2;
    reverse(all(s1));

    int shift;
    cin >> shift;

    // Calculate padding
    int pad1 = 50;
    int pad2 = 50 + (n-shift);

    // Add padding
    string p1, p2;
    for(int i = 0; i < pad1; i++) {
        p1 += ' ';
    }
    for(int i = 0; i < pad2; i++) {
        p2 += ' ';
    }
    s1 = p1 + s1;
    s2 = p2 + s2;

    // Debugging
    //cout << s1 << endl << s2 << endl;

    // Go bottom, top, etc...
    string ans;
    for(int i = 0; i < s1.length() || i < s2.length(); i++) {
        if(i < s2.length()) {
            ans.pb(s2[i]);
        }
        if(i < s1.length()) {
            ans.pb(s1[i]);
        }
    }

    // Print ans without padding
    for(auto& i : ans) {
        if(i != ' ') {
            cout << i;
        }
    }
    cout << endl;
	return 0;
}
