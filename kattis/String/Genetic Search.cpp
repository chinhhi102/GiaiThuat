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
int one(string pat, string all) {
    int index = 0;
    int total = 0;
    index = all.find(pat);
    while(index != -1) {
        total++;
        index = all.find(pat, index+1);
    }
    return total;
}
int two(string pat, string all) {
    vector<string> p;

    for(int i = 0; i < pat.size(); i++) {
        string temp = pat;
        temp.erase(i,1);
        p.push_back(temp);
    }

    sort(p.begin(), p.end());
    p.resize(distance(p.begin(), unique(p.begin(), p.end())));

    int total = 0;
    for(int s=0;s<p.size();s++) {
        total += one(p[s], all);
    }

    return total;
}
int three(string pat, string all) {
    string dna = "ATCG";

    vector<string> p;

    for(int i = 0; i < pat.size()+1; i++) {
        for(int j = 0; j < 4; j++) {
            string temp = pat;
            temp.insert(i, 1, dna[j]);
            p.push_back(temp);
        }
    }

    sort(p.begin(), p.end());
    p.resize(distance(p.begin(), unique(p.begin(), p.end())));

    int total = 0;
     for(int s=0;s<p.size();s++) {
        total += one(p[s], all);
    }

    return total;
}
int main(){
	io;
	string pat, all;
    while(cin >> pat && pat != "0" && cin >> all) {
        cout << one(pat, all) << " ";
        cout << two(pat, all) << " ";
        cout << three(pat, all) << endl;
    }
	return 0;
}
