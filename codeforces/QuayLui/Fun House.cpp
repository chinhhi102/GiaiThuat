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
int n, m;
const int MAXN = 30;
char grid[MAXN][MAXN];

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

void find_start(int& sx, int& sy, int& dir) {
    for (int i = 0; i < n; ++i) {
        if (grid[i][0] == '*') {
            sx = i;
            sy = 0;
            dir = 1;
            return;
        } else if (grid[i][m - 1] == '*') {
            sx = i;
            sy = m - 1;
            dir = 3;
            return;
        }
    }

    for (int j = 0; j < m; ++j) {
        if (grid[0][j] == '*') {
            sx = 0;
            sy = j;
            dir = 0;
            return;
        } else if (grid[n - 1][j] == '*') {
            sx = n - 1;
            sy = j;
            dir = 2;
            return;
        }
    }
}

int main(){
	io;
	int tc = 1;
    while (true) {
        scanf("%d %d", &m, &n);
        if (m == 0 or n == 0) break;

        for (int i = 0; i < n; ++i)
            scanf("%s", grid[i]);

        // try each starting spot
        int sx = 0;
        int sy = 0;
        int dir = 0;
        find_start(sx, sy, dir);

        sx += dx[dir];
        sy += dy[dir];

        while ((sx != 0 and sx != n - 1) and (sy != 0 and sy != m - 1)) {
            if (grid[sx][sy] == '/') {
                // 0 -> 3, 1 -> 2, 2 -> 1, 3 -> 0
                dir = dir ^ 3;
            } else if (grid[sx][sy] == '\\') {
                // 0 -> 1, 1 -> 0, 2-> 3, 3 -> 2
                dir = dir ^ 1;
            }

            sx += dx[dir];
            sy += dy[dir];
        }

        grid[sx][sy] = '&';
 
        printf("HOUSE %d\n", tc++);
        for (int i = 0; i < n; ++i) {
            printf("%s\n", grid[i]);
        }
    }

	return 0;
}
