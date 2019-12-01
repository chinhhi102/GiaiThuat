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
		while(scanf("%d",&n)!=EOF){
		priority_queue<int> pq;
		queue<int> q;
		stack<int> s;
		bool pq_v=1,q_v=1,s_v=1;
		while(n--){
			int st,val;
			c2(st,val);
			if(st==1){
				if(pq_v) pq.push(val);
				if(q_v) q.push(val);
				if(s_v) s.push(val);
			}else{
				if(pq_v)
					if(pq.empty()||pq.top()!=val)pq_v=0;
				else pq.pop();
				if(q_v)
					if(q.empty()||q.front()!=val)q_v=0;
				else q.pop();
				if(s_v)
					if(s.empty()||s.top()!=val)s_v=0;
				else s.pop();
			}
		}
		int ans=0;
		ans=(pq_v)+(q_v)+(s_v);
		if (ans==0)
        	printf("impossible\n");
    	else if (ans>1)
        	printf("not sure\n");
    		else
        		printf(pq_v ? "priority queue\n" : (q_v ? "queue\n" : "stack\n"));
	}
	return 0;
}
