#include<bits/stdc++.h>
using namespace std;
#define int long long

int f(int a, int b){
    int ret = 0;
    int zeroes = 0;
    for (int i = 1; i <= b; i <<= 1){
        if (b & i){
            b ^= i;
            if (!(a & b))
                ret += 1 << zeroes;
        }
        if (!(a & i))
            zeroes++;
    }
    return ret;
}

int rec(int a, int b){
    if (a == b) return 0;
    if (a == 0) return 2 * b - 1 + rec(1, b);
    
    int ret = 0;
    if (a & 1){
        ret += 2 * (f(a, b) - f(a, a));
        a++;
    }
    if (b & 1){
        ret += 2 * (f(b - 1, b) - f(b - 1, a));
        b--;
    }
    return ret + 3 * rec(a / 2, b / 2);
}

#undef int
int main(){
#define int long long
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int T;
	int a, b;
	cin >> T;
	while(T--){
		cin >> a >> b;
		cout << rec(a, b + 1) << endl;
	}	
}
