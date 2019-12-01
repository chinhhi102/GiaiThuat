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

struct Coord {
    int x;
    int y;
    Coord(int x, int y) : x(x), y(y) {}
};

bool grid[1002][1002];
bool visited[1002][1002];

void print_grid(){
	for (int i = 0; i < 7; ++i) {
        for (int j = 0; j < 8; ++j) {
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }
}

int main(){
	io;
	int N, M, g;
    scanf("%d%d",&N,&M);
    for (int i = 1; i <= N; ++i) {
        g = getchar(); // read past newline
        for (int j = 1; j <= M; ++j) {
            g = getchar();
            // cout << "setting (" << i << "," << j << ") to " << (g-48) << endl;
            grid[i][j] = (bool)(g-48); // 0 = ascii 48, 1 = ascii 49
            visited[i][j] = false;
        }
    }
    for(int i = 0; i <= N+1; ++i) {
        grid[i][0] = 0;
        grid[i][M+1] = 0;
        visited[i][0] = false;
        visited[i][M+1] = false;
    }
    for (int i = 1; i <= M+1; ++i) {
        grid[0][i] = 0;
        grid[N+1][i] = 0;
        visited[0][i] = false;
        visited[N+1][i] = false;
    }
    // print_grid();

    int coast = 0;
    queue<Coord> q;
    q.push(Coord(0,0));
    visited[0][0] = true;
    while(!q.empty()) { // bfs flood, count land, travel via water
        Coord c = q.front();
        q.pop();
        int s = q.size();
        // cout << "checking around coordinate (" << c.x << "," << c.y << ")" << endl;
        if ((c.x-1) >= 0 && (c.x-1) <= N+1) {
            if (grid[c.x-1][c.y]) {
                // cout << "found coast from coordinate (" << c.x << "," << c.y << ")" << endl;
                ++coast;
            }
            else if (!visited[c.x-1][c.y]) {
                visited[c.x-1][c.y] = true;
                q.push(Coord(c.x-1,c.y));
            }
        }
        if ((c.x+1) >= 0 && (c.x+1) <= N+1) {
            if (grid[c.x+1][c.y]) {
                // cout << "found coast from coordinate (" << c.x << "," << c.y << ")" << endl;
                ++coast;
            }
            else if (!visited[c.x+1][c.y]) {
                visited[c.x+1][c.y] = true;
                q.push(Coord(c.x+1,c.y));
            }
        }
        if ((c.y-1) >= 0 && (c.y-1) <= M+1) {
            if (grid[c.x][c.y-1]) {
                // cout << "found coast from coordinate (" << c.x << "," << c.y << ")" << endl;
                ++coast;
            }
            else if (!visited[c.x][c.y-1]) {
                visited[c.x][c.y-1] = true;
                q.push(Coord(c.x,c.y-1));
            }
        }
        if ((c.y+1) >= 0 && (c.y+1) <= M+1) {
            if (grid[c.x][c.y+1]) {
                // cout << "found coast from coordinate (" << c.x << "," << c.y << ")" << endl;
                ++coast;
            }
            else if (!visited[c.x][c.y+1]) {
                visited[c.x][c.y+1] = true;
                q.push(Coord(c.x,c.y+1));
            }
        }
    }
    printf("%d\n", coast);
	return 0;
}
