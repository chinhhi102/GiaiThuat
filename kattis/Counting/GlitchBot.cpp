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
int walk(int count, int* commands, int goal_x, int goal_y){
    int x = 0, y = 0, o = 0;
    for (int i = 0; i < count; i++){
        if (commands[i] == 0){
            if (o == 0) y++;
            else if (o == 1) x++;
            else if (o == 2) y--;
            else x--;
        }
        else if (commands[i] < 0){
            o = (o + 3) % 4;
        }
        else{
            o = (o + 1) % 4;
        }
    }
    return x == goal_x && y == goal_y;
}

int main(){
	int x = 0,y = 0;
    scanf("%d %d",&x,&y);
    int count = 0;
    scanf("%d",&count);
    int commands[count];
    char buffer[8];
    for (int i = 0; i < count; i++){
        scanf("%s", buffer);
        commands[i] = buffer[0] == 'F' ? 0 : buffer[0] == 'L' ? -1 : 1;
    }
    for (int i = 0; i < count; i++){
        int original = commands[i];
        int found = 0;
        for (int z = -1; z < 2; z++){
            if (z != original){
                commands[i] = z;
                if (walk(count, commands, x, y)){
                    printf("%d %s\n", i + 1, !z ? "Forward" : z < 0 ? "Left" : "Right");
                    found = 1;
                }
            }
            if (found) break;
        }
        if (found) break;
        commands[i] = original;
    }
	return 0;
}
