#ifndef competitive_programming_H
#define competitive_programming_H
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
#define fix(x) cout<<fixed<<setprecision(x)
#define UNIQUE(c) (c).resize(unique(all(c))-(c).begin())
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
#endif
void solve();
void fill(vector<string>& v, string& s){
    if(s==""){
        return;
    }
    v.push_back("");
    reverse(s.begin(),s.end());
    while(!s.empty()){
        if(s.back()==',') {
            v.pb("");
        }
        else{
            v[v.size()-1].pb(s.back());
        }
        s.pop_back();
    }
}

void place(vector<string>& board,string piece,bool color){
    char letter='p';
    if(piece.size()==3) {
        letter=piece[0];
        piece.erase(0,1);
    }
    if(color){
        letter=toupper(letter);
    }else{
        letter=tolower(letter);
    }
    int x=(piece[0]-'a')*4+2;
    int y=(7-(piece[1]-'1'))*2+1;
    board[y][x]=letter;
}
int main(){
	io;
	solve();
	return 0;
}

void solve(){
	string w,b;
    getline(cin,w);
    getline(cin,b);
    w=w.substr(7);
    b=b.substr(7);
    vector<string> whites;
    vector<string> blacks;
    fill(whites,w);
    fill(blacks,b);
    // Build the board
    string border="+---+---+---+---+---+---+---+---+";
    string space1="|...|:::|...|:::|...|:::|...|:::|";
    string space2="|:::|...|:::|...|:::|...|:::|...|";
    vector<string> board;
    board.push_back(border);
    board.push_back(space1);
    board.push_back(border);
    board.push_back(space2);
    board.push_back(border);
    board.push_back(space1);
    board.push_back(border);
    board.push_back(space2);
    board.push_back(border);
    board.push_back(space1);
    board.push_back(border);
    board.push_back(space2);
    board.push_back(border);
    board.push_back(space1);
    board.push_back(border);
    board.push_back(space2);
    board.push_back(border);
    for(auto i:whites){
        place(board,i,true);
    }
    for(auto i:blacks){
        place(board,i,false);
    }
    for(auto i:board){
        cout<<i<<endl;
    }
}
