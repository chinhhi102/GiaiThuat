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
//#include <unordered_set>
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
int sum(int n) {
    int total = 0;
    for(int i = 0; i <= n; i++) {
        total += i;
    }
    return total;
}

int getcollisions(unordered_map<int, unordered_map<string, int> > vals){
    int total = 0;
    for(unordered_map<int, unordered_map<string, int> >::iterator i=vals.begin();i!=vals.end();i++){
        vector<int> counts;
        for(unordered_map<string, int>::iterator j=(i->ss).begin();j!=(i->ss).end();j++) {
            counts.push_back(j->ss);
        }
        fora(j,0,counts.size()-1){
            fora(k,j+1,counts.size()){
                total+=counts[j]*counts[k];
            }
        }
    }
    return total;
}
int main(){
	io;
	int n;
    while(cin>>n&&n!=0) {
        unordered_set<string> s;
        unordered_map<int, unordered_map<string, int> > vals;
        cin.ignore();
        fora(i,0,n){
            string sentence;
            getline(cin, sentence);
            s.insert(sentence);
            int hash = 0;
            fora(c,0,sentence.size()){
                hash^=sentence[c];
            }
            vals[hash][sentence]++;
        }
        int c = getcollisions(vals);
        cout<<s.size()<<" "<<c<<endl;
    }
	return 0;
}
