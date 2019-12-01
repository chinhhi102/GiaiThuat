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

int main(){
	io;
	string s, t;
	getline(cin, s);
	getline(cin, t);
	pair<int, int> sb, sr, sd, tb, tr, td;
	if (s == "Black") {
		sb = {3, 1};
		sr = {0, 1};
		sd = {3, 1};
	} else if (s == "Blue") {
		sb = {3, 1};
		sr = {0, 1};
		sd = {0, 1};
	} else if (s == "Chocolate") {
		sb = {0, 1};
		sr = {0, 1};
		sd = {3, 1};
	} else if (s == "Lilac") {
		sb = {0, 1};
		sr = {0, 1};
		sd = {0, 1};
	} else if (s == "Red") {
		sb = {1, 1};
		sr = {1, 0};
		sd = {3, 1};
	} else if (s == "Cream") {
		sb = {1, 1};
		sr = {1, 0};
		sd = {0, 1};
	} else if (s == "Black-Red Tortie") {
		sb = {3, 1};
		sr = {1, 1};
		sd = {3, 1};
	} else if (s == "Blue-Cream Tortie") {
		sb = {3, 1};
		sr = {1, 1};
		sd = {0, 1};
	} else if (s == "Chocolate-Red Tortie") {
		sb = {0, 1};
		sr = {1, 1};
		sd = {3, 1};
	} else {
		sb = {0, 1};
		sr = {1, 1};
		sd = {0, 1};
	}
	if (t == "Black") {
		tb = {3, 1};
		tr = {0, 1};
		td = {3, 1};
	} else if (t == "Blue") {
		tb = {3, 1};
		tr = {0, 1};
		td = {0, 1};
	} else if (t == "Chocolate") {
		tb = {0, 1};
		tr = {0, 1};
		td = {3, 1};
	} else if (t == "Lilac") {
		tb = {0, 1};
		tr = {0, 1};
		td = {0, 1};
	} else if (t == "Red") {
		tb = {1, 1};
		tr = {1, 0};
		td = {3, 1};
	} else  {
		tb = {1, 1};
		tr = {1, 0};
		td = {0, 1};
	}
	double x[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	double q = (sb.ff + sb.ss) * (sr.ff + sr.ss) * (sd.ff + sd.ss) *
		(tb.ff + tb.ss) * (tr.ff + tr.ss) * (td.ff + td.ss);
	for (int i = 0; i < 2; i++)
		for (int j = 0; j < 2; j++)
			for (int k = 0; k < 2; k++)
				for (int l = 0; l < 2; l++)
					for (int m = 0; m < 2; m++)
						for (int n = 0; n < 2; n++) {
							int p = (i ? sb.ss : sb.ff) * (j ? sr.ss : sr.ff) *
								(k ? sd.ss : sd.ff) * (l ? tb.ss : tb.ff) *
								(m ? tr.ss : tr.ff) * (n ? td.ss : td.ff);
							if (!p) continue;
							if ((i == 0 || l == 0) && j == 1 && m == 1 && (k == 0 || n == 0)) x[0] += p / q;
							else if ((i == 0 || l == 0) && j == 1 && m == 1 && k == 1 && n == 1) x[1] += p / q;
							else if (i == 1 && l == 1 && j == 1 && m == 1 && (k == 0 || n == 0)) x[2] += p / q;
							else if (i == 1 && l == 1 && j == 1 && m == 1 && k == 1 && n == 1) x[3] += p / q;
							else if (j == 0 && m == 0 && (k == 0 || n == 0)) x[4] += p / q;
							else if (j == 0 && m == 0 && k == 1 && n == 1) x[5] += p / q;
							else if ((i == 0 || l == 0) && j == 1 && m == 0 && (k == 0 || n == 0)) {
								x[0] += p / (q * 2);
								x[6] += p / (q * 2);
							} else if ((i == 0 || l == 0) && j == 1 && m == 0 && k == 1 && n == 1) {
								x[1] += p / (q * 2);
								x[7] += p / (q * 2);
							} else if (i == 1 && l == 1 && j == 1 && m == 0 && (k == 0 || n == 0)) {
								x[2] += p / (q * 2);
								x[8] += p / (q * 2);
							} else if (i == 1 && l == 1 && j == 1 && m == 0 && k == 1 && n == 1) {
								x[3] += p / (q * 2);
								x[9] += p / (q * 2);
							} else if ((i == 0 || l == 0) && j == 0 && m == 1 && (k == 0 || n == 0)) {
								x[4] += p / (q * 2);
								x[6] += p / (q * 2);
							} else if ((i == 0 || l == 0) && j == 0 && m == 1 && k == 1 && n == 1) {
								x[5] += p / (q * 2);
								x[7] += p / (q * 2);
							} else if (i == 1 && l == 1 && j == 0 && m == 1 && (k == 0 || n == 0)) {
								x[4] += p / (q * 2);
								x[8] += p / (q * 2);
							} else if (i == 1 && l == 1 && j == 0 && m == 1 && k == 1 && n == 1) {
								x[5] += p / (q * 2);
								x[9] += p / (q * 2);
							}
						}
	string n[10] = {"Black", "Blue", "Chocolate", "Lilac", "Red", "Cream",
									"Black-Red Tortie", "Blue-Cream Tortie",
									"Chocolate-Red Tortie", "Lilac-Cream Tortie"};
	vector<pair<double, string> > v;
	for (int i = 0; i < 10; i++)
		if (x[i]) v.push_back({-x[i], n[i]});
	sort(v.begin(),v.end());
	fora(z,0,v.size())
		cout<<v[z].ss<<" "<<fixed<<setprecision(9)<<-v[z].ff<<endl;
	return 0;
}
