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

void solve();
void solve2();
struct node {
    bool ending = false;
    vector<node*> v;
};

bool insert(node* start,string num){
    int to_insert=num[num.size()-1]-'0';
    bool exists=start->v[to_insert]!=nullptr;
    if(exists){
        if(num.size()==1){
            return false;
        }
        if(start->v[to_insert]->ending){
            return false;
        }
        num.pop_back();
        return insert(start->v[to_insert],num);
    }
    node* n = new node;
    n->ending = false;
    n->v.resize(10, nullptr);
    start->v[to_insert] = n;
    if(num.size() == 1) {
        n->ending = true;
        return true;
    }
    num.pop_back();
    return insert(start->v[to_insert], num);
}
int main(){
	io;
	int cases;
	cin>>cases;
	while(cases--){
//		solve();
		solve2();
	}
	return 0;
}

void solve(){
	int n;
	cin>>n;
	map<string,bool> phones;
	vector<int> si;
	bool vaild=true;
	fora(i,0,n){
		string temp;
		cin>>temp;
		fora(j,0,si.size()){
			string s=temp;
			s.resize(si[j]);
			if(phones[s])
				vaild=false;
		}
		phones[temp]=true;
		si.pb(temp.size());
	}
	if(vaild)
		cout<<"YES"<<endl;
	else
		cout<<"NO"<<endl;
}
void solve2(){
	node* start=new node;
        start->ending=false;
        start->v.resize(10,nullptr);
        int numbers;
        cin>>numbers;
        bool valid=true;
        fora(j,0,numbers){
            string num;
            cin>>num;
            reverse(num.begin(),num.end());
            valid&=insert(start,num);
        }
        if(valid) {
            cout<<"YES"<<endl;
        }
        else {
            cout<<"NO"<<endl;
        }
}
