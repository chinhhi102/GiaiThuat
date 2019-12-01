#include <iostream>
#include <vector>

using namespace std;

struct entry {
    int freq;       // Frequency that this number occurs in the input list
    int parity;     // 0 for even number of factors, 1 for odd number
    int prod;       // Product of distinct prime factors
};

const int m = 3000000;      // Maximum input value
int n = 0;                  // Will be number of input values
vector<entry> v;

void extendedEratosthenes() {
    int i;
    for (i = 2; i * i <= m; ++i) {
        if (v[i].prod == 1) {
            for (int j = i, k = i; j <= m; j += i) {
                if (--k) {
                    v[j].parity ^= 1;
                    v[j].prod *= i;
                } else {
                    // j has a repeated factor of i: knock it out.
                    v[j].prod = 0;
                    k = i;
                }
            }
        }
    }

    // Fix up numbers with a prime factor above their square root.
    for (; i <= m; ++i) {
        if (v[i].prod && v[i].prod != i) {
            v[i].parity ^= 1;
        }
    }
}

void readInput() {
	int i;
    int nn;
    cin>>nn;
    for(i=1;i<=nn;i++){
    	++v[i].freq;
    	++n;
	}
}

void countCoprimes() {
    __int64 total = static_cast<__int64>(n) * (n - 1) / 2;
    for (int i = 2; i <= m; ++i) {
        if (v[i].prod) {
            // i must have no repeated factors.

            int c = 0;
            for (int j = i; j <= m; j += i) {
                c += v[j].freq;
            }

            total -= (v[i].parity * 2 - 1) * static_cast<__int64>(c) * (c - 1) / 2;
        }
    }

    cerr << "Total number of coprime pairs: " << total << "\n";
}

int main(int argc, char **argv) {
    cerr << "Initialising array...\n";
    entry initialElem = { 0, 0, 1 };
    v.assign(m + 1, initialElem);

    cerr << "Performing extended Sieve of Eratosthenes...\n";
    extendedEratosthenes();

    cerr << "Reading input...\n";
    readInput();

    cerr << "Counting coprimes...\n";
    countCoprimes();

    return 0;
}
