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

string convert(int row, char col) {
    char c = col + 'A';
    string ans = "";
    ans += c;
    ans += " ";
    ans += to_string(row + 1);
    return ans;
}

int main(){
	int T;
    cin >> T;
    int board[8][8];
    while (T-- > 0) {
        int r1, r2;
        char c1, c2;
        cin >> c1 >> r1 >> c2 >> r2;
        c1 -= 'A';
        c2 -= 'A';
        r1--;
        r2--;
        memset(board, 0, sizeof(board));
        if ((r1 + c1) % 2 != (r2 + c2) % 2) {
            cout << "Impossible\n";
        } else if (r1 == r2 && c1 == c2) {
            cout << 0 << " " << ((char)(c1 + 'A')) << ' ' << (r1 + 1) << '\n';
        } else {
            int dx[] = {1, -1, 1, -1};
            int dy[] = {1, 1, -1, -1};
            int r3;
            char c3;
            int ans = -1;
            for (int d = 0; ans < 0 && d < 4; ++d) {
                int nx = r1 + dx[d];
                int ny = c1 + dy[d];
                while (nx >= 0 && ny >= 0 && nx < 8 && ny < 8) {
                    if (nx == r2 && ny == c2) {
                        ans = 1;
                        break;
                    }
                    board[nx][ny] = 1;
                    nx += dx[d];
                    ny += dy[d];
                }
            }

            for (int d = 0; ans < 0 && d < 4; ++d) {
                int nx = r2 + dx[d];
                int ny = c2 + dy[d];
                while (nx >= 0 && ny >= 0 && nx < 8 && ny < 8) {
                    if (board[nx][ny] == 1) {
                        ans = 2;
                        r3 = nx;
                        c3 = ny;
                        break;
                    }
                    nx += dx[d];
                    ny += dy[d];
                }
            }

            if (ans == 1) {
                cout << "1 " << convert(r1, c1) << " " << convert(r2, c2) << '\n';
            } else {
                cout << "2 " << convert(r1, c1) << " " << convert(r3, c3) << " " << convert(r2, c2) << '\n';
            }
        }
    }
	return 0;
}
