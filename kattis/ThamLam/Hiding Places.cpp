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

int main(){
	io;
	 int n;
    cin >> n;
    while(n--){
        int board[8][8] = {};

        char x;
        int y;
        cin >> x >> y;
        board[8-y][x-'a'] = 1;
        int remaining = 63;
        int max = 1;
        while(remaining > 0){
            for(int i = 0; i < 8; ++i){
                for(int j = 0; j < 8; ++j){
                    if(board[i][j] == max){
                        int im2 = i - 2;
                        int im1 = i - 1;
                        int ip1 = i + 1;
                        int ip2 = i + 2;

                        int jm2 = j - 2;
                        int jm1 = j - 1;
                        int jp1 = j + 1;
                        int jp2 = j + 2;

                        if(im2 >= 0 && jm1 >= 0 && board[im2][jm1] == 0){
                            board[im2][jm1] = max+1;
                            --remaining;
                        }
                        if(im2 >= 0 && jp1 < 8 && board[im2][jp1] == 0){
                            board[im2][jp1] = max+1;
                            --remaining;
                        }
                        if(ip2 < 8 && jm1 >= 0 && board[ip2][jm1] == 0){
                            board[ip2][jm1] = max+1;
                            --remaining;
                        }
                        if(ip2 < 8 && jp1 < 8 && board[ip2][jp1] == 0){
                            board[ip2][jp1] = max+1;
                            --remaining;
                        }

                        if(im1 >= 0 && jm2 >= 0 && board[im1][jm2] == 0){
                            board[im1][jm2] = max+1;
                            --remaining;
                        }
                        if(ip1 < 8 && jm2 >= 0 && board[ip1][jm2] == 0){
                            board[ip1][jm2] = max+1;
                            --remaining;
                        }

                        if(im1 >= 0 && jp2 < 8 && board[im1][jp2] == 0){
                            board[im1][jp2] = max+1;
                            --remaining;
                        }
                        if(ip1 < 8 && jp2 < 8 && board[ip1][jp2] == 0){
                            board[ip1][jp2] = max+1;
                            --remaining;
                        }
                    }
                }
            }
            ++max;
        }
        cout << max-1;
        for(int i = 0; i < 8; ++i) {
            for (int j = 0; j < 8; ++j) {
                if(board[i][j] == max){
                    cout << " " <<char('a'+j) << 8-i;
                }
            }
        }
        cout << endl;
    }
	return 0;
}
