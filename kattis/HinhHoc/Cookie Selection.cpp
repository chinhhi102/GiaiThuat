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
#include <list>
#include <stack>
#include <iterator>
#include <complex>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
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

ll stoi(string s){
	ll ans=0;
	fora(i,0,s.size()){
		ans=ans*10+s[i]-'0';
	}
	return ans;	
}
void send_cookie(multiset<unsigned int>& diameters,
                 multiset<unsigned int>::iterator& median){
    multiset<unsigned int>::iterator new_median=median;
    if (diameters.size()%2)
        ++new_median;
    else
        --new_median;
	diameters.erase(median);
	median = new_median;
}

void add_cookie(multiset<unsigned int>& diameters,
                multiset<unsigned int>::iterator& median,
                unsigned int diameter){
    diameters.insert(diameter);
    if (diameters.size() == 1)
        median = diameters.begin();
    else if (diameters.size() % 2){
        if (diameter < *median)
            --median;
    }
    	else if (diameter >= *median)
            ++median;
}

int main(){
	multiset<unsigned int> diameters;
    multiset<unsigned int>::iterator median;

    for (string operation; cin>>operation;){
        if (operation=="#"){
            cout<<*median<<'\n';
            send_cookie(diameters,median);
        }
        else
            add_cookie(diameters, median, stoi(operation));
    }
	return 0;
}
