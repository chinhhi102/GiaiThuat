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

int main(){
	io;
	int r,s;
    vector<string> v;
    cin >> r >> s;
    for(int i = 0; i < r; ++i){
        string str;
        cin >> str;
        v.push_back(str);
    }
    int h = 0;
    int max = 0;
    for(int i = 0; i < r; ++i){
        for(int j = 0; j < s; ++j){
            if(v[i][j] == 'o'){
                if(i > 0 && v[i-1][j] == 'o'){
                    ++h;
                }
                if(i > 0 && j+1 < s && v[i-1][j+1] == 'o'){
                    ++h;
                }
                if(j+1 < s && v[i][j+1] == 'o'){
                    ++h;
                }
                if(i+1 < r && j+1 < s && v[i+1][j+1] == 'o'){
                    ++h;
                }
            } else {
                int seat = 0;
                if(i > 0){
                    if(j > 0 && v[i-1][j-1] == 'o'){
                        seat +=  1;
                    }
                    if(v[i-1][j] == 'o'){
                        seat +=  1;
                    }
                    if(j+1 < s && v[i-1][j+1] == 'o'){
                        seat +=  1;
                    }
                }
                if(j > 0 && v[i][j-1] == 'o'){
                    seat +=  1;
                }
                if(j+1 < s && v[i][j+1] == 'o'){
                    seat +=  1;
                }
                if(i+1 < r){
                    if(j > 0 && v[i+1][j-1] == 'o'){
                        seat +=  1;
                    }
                    if(v[i+1][j] == 'o'){
                        seat +=  1;
                    }
                    if(j+1 < s && v[i+1][j+1] == 'o'){
                        seat +=  1;
                    }
                }
                max = seat > max ? seat : max;
            }
        }
    }
    cout << h+max << endl;
	return 0;
}
