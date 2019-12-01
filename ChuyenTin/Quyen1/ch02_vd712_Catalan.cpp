#include<bits/stdc++.h>
using namespace std;
typedef string bigNum;
int cmp(bigNum a, bigNum b){
	while(a.size()<b.size()) a='0'+a;
	while(b.size()<a.size()) b='0'+b;
	if(a < b) return -1;
	if(a == b) return 0;
	return 1;
}
bigNum add(bigNum a, bigNum b){
	while(a.size()<b.size()) a='0'+a;
	while(b.size()<a.size()) b='0'+b;
	bigNum c = "";
	int carry = 0, s;
	for(int i=a.size() - 1; i >= 0; i--){
		s = (a[i] - '0') + (b[i] - '0') + carry;
		carry = (s >= 10);
		c = char(s % 10 + '0') + c;
	}
	if(carry)
		c = "1" + c;
	return c;
}
bigNum sub(bigNum a, bigNum b){
	while(a.size()<b.size()) a='0'+a;
	while(b.size()<a.size()) b='0'+b;
	bigNum c = "";
	int borrow = 0, s;
	for(int i=a.size() - 1; i >= 0; i--){
		s = (a[i] - '0') - (b[i] - '0') - borrow;
		if(s < 0){
			s += 10;
			borrow = 1;
		}else borrow = 0;
		c = char(s%10 + '0') + c;		
	}
	while(c.size() && c[0] == '0') c = string(c.begin() + 1, c.end());
	return c;
}
bigNum mul1(bigNum a, int b){
	bigNum c;
	c = "";
	int s;
	int carry = 0;
	for( int i = a.size() - 1; i >= 0; i--){
		s = (a[i] - '0') * b + carry;
		carry = s / 10;
		c = char(s%10 + '0') + c;
	}
	if(carry)
		c = char(carry + '0') + c;
	return c;
}
bigNum bigDiv1(bigNum a, int b){
	bigNum c;
	int hold = 0, s;
	c = "";
	for(int i = 0; i < a.size(); i++){
		hold = (a[i] - '0') + 10*hold;
		s = hold / b;
		hold = hold % b;
		c = c + char(s%10 + '0');
	}
	while(c.size() && c[0] == '0') c = string(c.begin() + 1, c.end());
	return c;
}
bigNum Catalan(int n){
	bigNum s;
	s = "1";
	for(int k = (n + 2); k <= (2*n); k++){ s = mul1(s, k); }
	for(int k = 1; k <= n; k++) { s = bigDiv1(s, k);	}
	return s;
}
int main(){
	int N;
	cout << "Nhap N: ";
	cin >> N;
	cout << Catalan(N);
}
