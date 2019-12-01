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
int stoi(string s){
	int sum=0;
	fora(i,0,s.size()){
		sum=sum*10+(s[i]-'0');
	}
	return sum;
}
int main(){
	io;
	vector<int> commands;
    int k, c;
    cin>>k>>c;
    for(int i=0;i<c;i++) {
        cin.ignore();
        if(cin.peek()=='u'){
            string undo;
            cin>>undo;
            int drops;
            cin>>drops;
            fora(i,0,drops){
                commands.pop_back();
            }
        }
        else{
            int n;
            cin >> n;
            commands.push_back(n);
        }
    }
    int spot=0;
    fora(i,0,commands.size()){
        spot+=commands[i];
        spot%=k;
        while(spot<0)
            spot += k;
    }
    cout<<spot<<endl;
	return 0;
}
