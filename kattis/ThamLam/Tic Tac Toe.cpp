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
#define fors(i,a,b) for(int i=a;i>=b;i--)
#define men(a) menset(a,0,sizeof(a))
#define sc(x) scanf("%d",&x);
#define scll(x) scanf("%lld",&x);
#define c1(a) cin>>a
#define c2(a,b) cin>>a>>b
#define c3(a,b,c) cin>>a>>b>>c
#define pb push_back
#define ff first
#define ss second
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
	int n;sc(n);
	cin.ignore();
	while(n--){
		char ttt[4][4];
		int countdO[4]={},countdX[4]={},countnO[4]={},countnX[4]={},countcO[3]={},countcX[3]={},sX(0),sO(0),floatt(0);
		fora(i,0,4)gets(ttt[i]);
		fora(i,0,4){
			fora(j,0,4){
				if(ttt[i][j]=='X'){
				sX++;
				countdX[i]++;
				countnX[j]++;
				if(i==j)countcX[0]++;
				if(i+j==2)countcX[1]++;
				}
				if(ttt[i][j]=='O'){
				sO++;
				countdO[i]++;
				countnO[j]++;
				if(i==j)countcO[0]++;
				if(i+j==2)countcO[1]++;
				}
				if(ttt[i][j]=='.')floatt++;
			}
		}
		printf("%s\n",((sO!=sX&&sX!=sO+1)||(sO==sX&&(countdX[0]==3||countdX[1]==3||countdX[2]==3||
													countnX[0]==3||countnX[1]==3||countnX[2]==3||
													countcX[0]==3||countcX[1]==3
													
													))||(sO+1==sX&&(countdO[0]==3||countdO[1]==3||countdO[2]==3||
													countnO[0]==3||countnO[1]==3||countnO[2]==3||
													countcO[0]==3||countcO[1]==3
													
													))||((countdX[0]==3||countdX[1]==3||countdX[2]==3||
													countnX[0]==3||countnX[1]==3||countnX[2]==3||
													countcX[0]==3||countcX[1]==3
													
													)&&(countdO[0]==3||countdO[1]==3||countdO[2]==3||
													countnO[0]==3||countnO[1]==3||countnO[2]==3||
													countcO[0]==3||countcO[1]==3
													
													)))?"no":"yes");
	}
	return 0;
}
