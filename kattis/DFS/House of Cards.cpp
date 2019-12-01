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
//#include <tuple>
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
void increment(char* str, size_t len){
    size_t index=len-1;
    while(str[index]=='9') str[index--]='0';
    str[index]=str[index]=='X'?'1':(char)(str[index]+1);
}
int ends_with_101(char* str, size_t len){
    int n=atoi(str+len-3);
//    cout<<n<<" ";
    if (!((n%2)&1)) return 0;
    n>>=1;
    if((n%2)&1) return 0;
    n>>=1;
    return (n%2)&1;
}
void update_buffer(char* str, size_t l){
    while (atoi(str+(l-3))%8!=0&&!ends_with_101(str,l))increment(str,l);
}

int numeric_find(int n){
    while(1){
        int rem=n%8;
        if (rem==0||rem==5) return n;
        n++;
    }
}
int main(){
	io;
	char buffer[10003];
    scanf("%s",buffer+1);
    size_t len=strlen(buffer+1);
    if (len<10)printf("%d\n",numeric_find(atoi(buffer+1)));
    else{
        buffer[0]='X';
        update_buffer(buffer,len+1);
        printf("%s\n", buffer[0]=='X'?buffer+1:buffer);
    }
	return 0;
}
