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
	int width;
    cin >> width;
    while(width != 0){
        int max_width = 0;
        int current_width = 0;
        int max_height = 0;
        int total_height = 0;
        int w,h;
        cin >> w >> h;
        while(w != -1 && h != -1){
            if(current_width + w <= width){
                current_width += w;
                max_height = h > max_height ? h : max_height;
            } else {
                max_width = current_width > max_width ? current_width : max_width;
                current_width = w;
                total_height += max_height;
                max_height = h;
            }
            cin >> w >> h;
        }
        max_width = current_width > max_width ? current_width : max_width;
        total_height += max_height;
        cout << max_width << " x " << total_height << endl;
        cin >> width;
    }
	return 0;
}
