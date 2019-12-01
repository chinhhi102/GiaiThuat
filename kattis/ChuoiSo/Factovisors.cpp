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
const int SQRTN = 50000;

vector<int> primes;
vector<pair<int, int> > factors;

int sieve[SQRTN];

void gen_sieve() {
    memset(sieve, -1, sizeof(sieve));

    primes.push_back(2);
    for (int i = 2; i < SQRTN; i += 2) {
        sieve[i] = 2;
    }

    for (int i = 3; i < SQRTN; i += 2) {
        if (sieve[i] == -1) {
            sieve[i] = i;
            primes.push_back(i);
            for (long long j = 1LL * i * i; j < SQRTN; j += 2LL * i) {
                sieve[j] = i;
            }
        }
    }
}

void factorize(long long m) {
    factors.clear();
    for (int i : primes) {
        if (i > m) {
            break;
        }

        int count = 0;
        while (m % i == 0) {
            m /= i;
            ++count;
        }

        if (count > 0) {
            factors.push_back(make_pair(i, count));
        }
    }

    if (m > 1) {
        factors.push_back(make_pair(m, 1));
    }
}

int count_factor(int p, int n) {
    long long power = p;
    int count = 0;

    while (power <= n) {
        count += n / power;

        power *= p;
    }

    return count;
}

bool divides_factorial(int n, int m) {
    if (m == 0) {
        return false;
    }

    if (m == 1 or n >= m) {
        return true;
    }

    factorize(m);

    for (pair<int, int> factor_pair : factors) {
        if (count_factor(factor_pair.first, n) < factor_pair.second) {
            return false;
        }
    }

    return true;
}

int main(){
	io;
	gen_sieve();

    int n, m;
    while (scanf("%d %d", &n, &m) == 2) {
        const char* out_str = divides_factorial(n, m) ? "divides" : "does not divide";
        printf("%d %s %d!\n", m, out_str, n);
    }
	return 0;
}
