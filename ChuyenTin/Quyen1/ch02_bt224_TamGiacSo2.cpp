#include<bits/stdc++.h>
using namespace std;
#define MAX 101
#define int long long

struct bigNum{
	int sign = 1;
	string num = "";
};

bigNum lmin[2][MAX], lmax[2][MAX], p1, p2, p3, p4;
int a[MAX][MAX] = {};

int cmp(bigNum a, bigNum b){
	if(a.sign < b.sign) return -1;
	if(a.sign > b.sign) return 1;
	while(a.num.size() < b.num.size()) a.num = '0' + a.num;
	while(b.num.size() < a.num.size()) b.num = '0' + b.num;
	if(a.num == b.num) return 0;
	if(a.num > b.num) return a.sign;
	return -1*a.sign;
}

bigNum mul(bigNum a, int b){
	bigNum c;
	if(a.num == "0" || b == 0){
		c.sign = 1;
		c.num = "0";
		return c;
	}
	if(b > 0) c.sign = a.sign;
	else c.sign = -a.sign;
	b = abs(b);
	int s, carry = 0;
	for(int i = a.num.size() - 1; i >= 0; i--){
		s = (a.num[i] - 48) * b + carry;
		carry = s / 10;
		c.num = char(s%10 + 48) + c.num;
	}
	while(carry){
		c.num = char(carry%10 + 48) + c.num;
		carry /= 10;
	}
	return c;
}

void getMinMax(bigNum a, bigNum b, bigNum& ma, bigNum& mi){
	if(cmp(a, b) == 1){
		ma = a;
		mi = b;
	}else{
		ma = b;
		mi = a;
	}
}

string str(int x){
	string s = "";
	while(x){
		s = char(x%10 + 48) + s;
		x /= 10;
	}
	return s;
}

#undef int
int main(){
#define int long long
	int n;
	cin >> n;
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= i; j++) cin >> a[i][j];
	lmin[1][1].sign = (a[1][1] < 0 ? -1 : 1);
	lmin[1][1].num = str(abs(a[1][1]));
	lmax[1][1] = lmin[1][1];
	for(int i = 2; i <= n; i++){
		getMinMax(mul(lmax[(i - 1) & 1][1], a[i][1]), mul(lmin[(i - 1) & 1][1], a[i][1]), lmax[i & 1][1], lmin[i & 1][1]);
		getMinMax(mul(lmax[(i - 1) & 1][i - 1], a[i][i]), mul(lmin[(i - 1) & 1][i - 1], a[i][i]), lmax[i & 1][i], lmin[i & 1][i]);
		for(int j = 2; j < i; j++){
			getMinMax(mul(lmax[(i - 1) & 1][j - 1], a[i][j]), mul(lmin[(i - 1) & 1][j - 1], a[i][j]), p1, p2);
			getMinMax(mul(lmax[(i - 1) & 1][j], a[i][j]), mul(lmin[(i - 1) & 1][j], a[i][j]), p3, p4);
			if(cmp(p1, p3) == 1) lmax[i & 1][j] = p1;
			else lmax[i & 1][j] = p3;
			if(cmp(p2, p4) == -1) lmin[i & 1][j] = p2;
			else lmin[i & 1][j] = p4;
		}
	}
	p1 = lmax[n & 1][1];
	for(int i = 2; i <= n; i++) 
		if(cmp(lmax[n & 1][i], p1) == 1)
			p1 = lmax[n & 1][i]; 
	if(p1.sign == -1) cout << '-';
	cout << p1.num;
}

/*
5
7
3 8
8 1 0
2 7 4 4
4 5 -2 6 5

5
5
1 5
1 1 5
1 1 1 5
1 1 1 1 5

5880
*/
