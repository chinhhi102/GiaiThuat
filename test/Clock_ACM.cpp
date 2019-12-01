#include <bits/stdc++.h>
 
using namespace std;
 
#define debug(a) cout << #a << ": " << a << endl
#define fto(i, l, r) for(int i = l; i <= r; ++i)
#define fdto(i, r, l) for(int i = r; i >= l; --i)
 
const int MAX_N = 1000005;
 
int n;
int a[MAX_N];
int b[MAX_N];
 
int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        b[i] = a[i];
    }
 
    int res = 1000000007;
 
    for (int s = 0; s <= 12; s++) {
        int sum = s;
        for (int i = 1; i <= n; i++) {
            a[i] = b[i];
        }
 
        a[1] = (a[1] - s  + 12) % 12;
        if (a[1] == 0)
            a[1] = 12;
 
 
        for (int i = 1; i <= n - 1; i++) {
            int t = 12 - a[i];
            sum += t;
            a[i + 1] = (a[i + 1] - t + 12) % 12;
            if (a[i + 1] == 0) {
                a[i + 1] = 12;
            }
        }
 
        sum += (12 - a[n]) % 12;
        res = min(res, sum);
    }
 
    cout << res;
    return 0;
}
