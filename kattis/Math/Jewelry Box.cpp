#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
ll x,y;
ld vol(ld h){
    ld a=(x-2.0*h);
    ld b=(y-2.0*h);
    return h*a*b;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int T;
    scanf("%d", &T);
    while (T--){
        scanf("%lld %lld", &x, &y);
        ld a = 12.0L;
        ld b = -4.0L *(x+y);
        ld c = 1.0L *x*y;
        ld h1 = (-b+sqrt(b*b-4*a*c))/(2.0*a);
        ld h2 = (-b-sqrt(b*b-4*a*c))/(2.0*a);
        printf("%.11Lf\n", max(vol(h1),vol(h2)));
    }
}
