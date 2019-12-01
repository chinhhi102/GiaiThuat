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
bool isprime(int n) {
    if(n < 2) {
        return false;
    }
    if(n == 2) {
        return true;
    }

    for(int i = 2; i <= sqrt(n); i++) {
        if(n % i == 0) {
            return false;
        }
    }
    return true;
}
int total = 0;
int curr = 0;
int numleft = 0;
vector<int> numcount;
set<int> prime;

void process() {
    if(isprime(curr)) {
        prime.insert(curr);
    }
    if(numleft == 0) {
        return;
    }
    for(int i=0;i<10;i++){
        if(numcount[i]>0){
            curr=curr*10+i;
            numleft--;
            numcount[i]--;
            process();

            numcount[i]++;
            numleft++;
            curr/=10;
        }
    }
}
int main(){
	io;
	int cases;
    cin >> cases;
    while(cases--) {
        string s;
        cin>>s;

        total = 0;
        numleft = 0;
        curr = 0;
        prime.clear();
        numcount.clear();
        numcount.resize(10,0);

        fora(i,0,s.size()){
            numcount[s[i]-'0']++;
            numleft++;
        }
        process();
        cout<<prime.size()<<endl;
    }
	return 0;
}