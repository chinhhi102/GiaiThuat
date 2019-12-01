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
#define M_PI 3.14159265358979323846
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
void getval(vector<int>& v, vector<int>& ret, int subset) {
    int curr = 0;
    while(subset > 0) {
        if(subset % 2 == 1) {
            ret.pb(v[curr]);
        }
        subset >>= 1;
        curr++;
    }
}

int getsum(vector<int>& v, int subset) {
    vector<int> vals;
    getval(v, vals, subset);
    int total = 0;
    fora(i,0,vals.size())
        total += vals[i];
    return total;
}
int main(){
	io;
	int cases;
    cin >> cases;

    for(int casenum = 0; casenum < cases; casenum++) {
        int n;
        cin >> n;
        vector<int> v(n);
        fora(i,0,v.size()) {
            cin >> v[i];
        }

        // Maps sum to subset value
        map<int,int> m;
        for(int i = 0; i < (1<<n); i++) {
            int sum = getsum(v, i);
            if(m.count(sum) > 0 && (m[sum] ^ i) != 0) {
                cout << "Case #" << casenum+1 << ":" << endl;
                vector<int> set1;
                getval(v, set1, i);
                fora(i,0,set1.size()) {
                    cout << set1[i] << " ";
                }
                cout << endl;
                vector<int> set2;
                getval(v, set2, m[sum]);
                fora(i,0,set2.size()) {
                    cout << set2[i] << " ";
                }
                cout << endl;
                break;
            }

            m[sum] = i;
        }
    }
	return 0;
}
