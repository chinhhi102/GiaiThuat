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

void solve();
const int N=1e4+10,M=5e4+10,Z=1e9+7,ms63=1061109567;  
int casenum,casei;  
char e[128],v[128];  
char s[N],w[M];  
void init(){  
    e['b']=v['b']='b';  
    e['c']=v['c']='c';  
    e['d']=v['d']='d';  
    e['g']=v['g']='g';  
    e['k']=v['k']='k';  
    e['n']=v['n']='n';  
    e['p']=v['p']='p';  
    e['t']=v['t']='t';  
    for(char ch='a';ch<='z';ch++)
		if(v[ch]==0){  
        	char h=ch-1;
        	char t=ch+1;  
        	while(1){  
        	    if(isalpha(h)){  
           	    	if(e[h]){  
                    	v[ch]=h;  
                    	break;  
                	}else
						h--;  
            	}  
	            if(isalpha(t)){  
    	            if(e[t]){  
        	        	v[ch]=t;  
            	        break;  
            	    }else
						t++;  
            	}  
        	}  
    	}  
}  
int main(){
	io;
	solve();
	return 0;
}

void solve(){
	init();  
    while(~scanf("%s",s)){  
        bool ST=s[0]<='Z';  
        if(ST)s[0]+=32;  
        s[0]=v[s[0]];  
        int m=0;  
        bool flag=0;  
        for(int i=0;s[i];i++){  
            if(flag&&e[s[i]])
				s[i]=s[0];  
            if(s[i]=='-')
				flag=1;  
            else
				w[m++]=s[i];  
        }  
        char ch=w[m-1];  
        if(e[ch]){  
            int d1=abs(ch-'a');  
            int d2=abs(ch-'o');  
            int d3=abs(ch-'u');  
            int d=min(d1,min(d2,d3));  
            if(d1==d){  
                w[m++]='a';  
                w[m++]='h';  
            }else if(d2==d){  
                w[m++]='o';  
                w[m++]='h';  
            }else{  
                w[m++]='u';  
                w[m++]='h';  
            }  
        }
		w[m]=0;  
        if(ST){
			w[0]-=32;
			ST=0;
		}  
        printf("%s",w);  
        putchar(getchar());  
    }  
}
