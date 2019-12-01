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
int inde;

bool compare(vector<string> lhs, vector<string> rhs) {
    return lhs[inde] < rhs[inde];
}
int main(){
	io;
	string line;
	getline(cin,line);
	istringstream iss(line.substr());
	string token;
	vector<string> split;
	while(iss>>token){
		split.pb(token);	
	}
	int num_songs;
	cin>>num_songs;
	cin.ignore();
	vector<vector<string> > v;
	for(int i = 0; i < num_songs; i++) {
        vector<string> song;
        for(int j = 0; j < split.size(); j++) {
            string temp;
            cin >> temp;
            song.push_back(temp);
        }
        v.push_back(song);
    }
    int num_queries;
    cin>>num_queries;
    cin.ignore();
    fora(i,0,num_queries){
    	string query;
    	cin>>query;
    	for(int i = 0; i < split.size(); i++) {
            if(split[i] == query) {
                inde = i;
            }
        }
		stable_sort(v.begin(), v.end(), compare);
		cout << line << endl;
        fora(i,0,v.size()){
            fora(j,0,v[i].size()){
                cout<<v[i][j]<<" ";
            }
            cout<<endl;
        }
        cout<<endl;
	}
	return 0;
}
