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
#include <ctype.h>
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
bool cmd(int x,int y){return x>y;}
int main(){
	io;
	int arr[6];
	fora(i,0,6)
		cin>>arr[i];
	int h1,h2;
	cin>>h1>>h2;
	sort(arr,arr+6,cmd);
	int found = 0;
    int indices[6];
    for (int i = 0; i < 6; i++){
        for (int j = i + 1; j < 6; j++){
            for (int k = j + 1; k < 6; k++){
                if (arr[i] + arr[j] + arr[k] == h1){
                    found++;
                    indices[0] = i;
                    indices[1] = j;
                    indices[2] = k;
                }
                else if (arr[i] + arr[j] + arr[k] == h2){
                    found++;
                    indices[3] = i;
                    indices[4] = j;
                    indices[5] = k;
                }
                if (found == 2){
                	fora(i,0,6)
                	cout<<arr[indices[i]]<<" ";
                	return 0;
				}
			}
		}
	}
	return 0;
}
