#include<bits/stdc++.h>
using namespace std;
struct bigNum{
	int sign;
	string num;
};

int cmp(bigNum a, bigNum b){
	int si = (a.sign < b.sign) ? -1 : ((a.sign == b.sign) ? 0 : 1);
	if(si != 0) return si;
	while(a.num.size() < b.num.size()) a.num = '0' + a.num;
	while(b.num.size() < a.num.size()) b.num = '0' + b.num;
	si = (a.num < b.num) ? -1 : ((a.num == b.num) ? 0 : 1);
	return si * a.sign;
}
bigNum sub(bigNum, bigNum);
bigNum add(bigNum a, bigNum b){
	int si = (a.sign < b.sign) ? -1 : ((a.sign == b.sign) ? 0 : 1);
	if(si == 0){
		bigNum c;
		c.sign = a.sign;
		while(a.num.size() < b.num.size()) a.num = '0' + a.num;
		while(b.num.size() < a.num.size()) b.num = '0' + b.num;
		int s, carry = 0;
		for(int i = a.num.size() - 1; i >= 0; i--){
			s = a.num[i] + b.num[i] - (2*48) + carry;
			carry = s / 10;
			c.num = char(s%10 + '0') + c.num;
		}
		if(carry) c.num = char(carry + '0') + c.num;
		while(c.num[0] == '0' && c.num.size() > 1) c.num = string(c.num.begin() + 1, c.num.end());
		if(c.num == "0") c.sign = 1; 
		return c;
	}else{
		if(si == -1){
			a.sign *= -1;
			return sub(b, a);
		}
		b.sign *= -1;
		return sub(a, b);
	}
}

bigNum sub(bigNum a, bigNum b){
	int si = (a.sign < b.sign) ? -1 : ((a.sign == b.sign) ? 0 : 1);
	if(si == 0){
		if(b.sign == -1){
			b.sign *= -1;
			return add(b, a);
		}
		bigNum c;
		if(cmp(a,b) < 0){
			c = sub(b, a);
			c.sign = -1;
			return c;
		}
		c.num = "";
		int s, borrow = 0;
		while(a.num.size() < b.num.size()) a.num = '0' + a.num;
		while(b.num.size() < a.num.size()) b.num = '0' + b.num;
		for(int i = a.num.size() - 1; i >= 0; i--){
			s = a.num[i] - b.num[i] - borrow;
			if(i != 0 && s < 0){
				borrow = 1;
				s += 10;
			}else if(i == 0 && s < 0) borrow = 1;
			 else borrow = 0;
			c.num = char(abs(s) + '0') + c.num;
		}
		c.sign = (borrow ? -1 : 1);
		while(c.num[0] == '0' && c.num.size() > 1) c.num = string(c.num.begin() + 1, c.num.end());
		if(c.num == "0") c.sign = 1;
		return c;
	}else{
		b.sign *= -1;
		return add(a, b);
	}
}

bigNum mul1(bigNum a, int b){
	bigNum c;
	c.sign = a.sign;
	c.num = "";
	if(b < 0) c.sign *= -1, b *= -1;
	int carry = 0, s;
	for(int i = a.num.size() - 1; i >= 0; i--){
		s = (a.num[i] - '0') * b + carry;
		carry = s / 10;
		c.num = char(s%10 + '0') + c.num;
	}
	if(carry) c.num = char(carry + '0') + c.num;
	while(c.num[0] == '0' && c.num.size() > 1) c.num = string(c.num.begin() + 1, c.num.end());
	if(c.num == "0") c.sign = 1;
	return c;
}

bigNum mul2(bigNum a, bigNum b){
	bigNum c, sum;
	c.sign = 1;
	c.num = "0";
	for(int i = a.num.size() - 1; i >= 0; i--){
		sum = mul1(b, (a.num[i] - '0'));
		for(int j = 0; j < a.num.size() - i - 1; j++) sum.num += '0';
		c = add(c, sum);
	}
	c.sign = (a.sign == b.sign ? 1 : -1);
	while(c.num[0] == '0' && c.num.size() > 1) c.num = string(c.num.begin() + 1, c.num.end());
	if(c.num == "0") c.sign = 1;
	return c;
}

bigNum bigDiv1(bigNum a, int b){
	if(b == 0){
		cout << "Error div by 0!" << endl;
		exit(0);
	}
	int s, i, hold;
	bigNum c;
	hold = s = 0;
	c.num = "";
	for(int i = 0; i < a.num.size(); i++){
		hold = hold * 10 + (a.num[i] - '0');
		s = hold / b;
		hold = hold % b;
		c.num = c.num + char(s + '0');
	}
	c.sign = a.sign;
	if(b < 0) c.sign = c.sign * (-1);
	while(c.num[0] == '0' && c.num.size() > 1) c.num = string(c.num.begin() + 1, c.num.end());
	if(c.num == "0") c.sign = 1;
	return c;
}

int bigMod1(bigNum a, int b){
	if(b == 0){
		cout << "Error div by 0!" << endl;
		exit(0);
	}
	int s, i, hold;
	bigNum c;
	hold = s = 0;
	c.num = "";
	for(int i = 0; i < a.num.size(); i++){
		hold = hold * 10 + (a.num[i] - '0');
		s = hold / b;
		hold = hold % b;
		c.num = c.num + char(s + '0');
	}
	hold = (a.sign * b >= 0 ? hold : -hold);
	return hold;
}

bigNum bigDiv2(bigNum a, bigNum b){
	if(b.num == "0"){
		cout << "Error div by 0!" << endl;
		exit(0);
	}
	int si = (a.sign == b.sign ? 1 : -1);
	a.sign = b.sign = 1;
	bigNum kb[10];
	int k;
	bigNum c, hold;
	kb[0].sign = 1;
	kb[0].num = "0";
	for(int i = 1; i < 10; i++){ kb[i] = add(kb[i - 1], b); }
	hold.num = c.num = "";
	hold.sign = c.sign = 1;
	for(int i = 0; i < a.num.size(); i++){
		hold.num = hold.num + a.num[i];
		k = 1;
		while(cmp(hold, kb[k]) != -1) k++;
		c.num = c.num + char(k - 1 + '0');
		hold = sub(hold, kb[k - 1]);
	}
	c.sign = si;
	while(c.num[0] == '0' && c.num.size() > 1) c.num = string(c.num.begin() + 1, c.num.end());
	if(c.num == "0") c.sign = 1;
	return c;
}

bigNum bigMod2(bigNum a, bigNum b){
	if(b.num == "0"){
		cout << "Error div by 0!" << endl;
		exit(0);
	}
	int si = (a.sign == b.sign ? 1 : (a.sign));
	a.sign = b.sign = 1;
	bigNum kb[10];
	int k;
	bigNum c, hold;
	kb[0].sign = 1;
	kb[0].num = "0";
	for(int i = 1; i < 10; i++){ kb[i] = add(kb[i - 1], b); }
	hold.num = c.num = "";
	hold.sign = c.sign = 1;
	for(int i = 0; i < a.num.size(); i++){
		hold.num = hold.num + a.num[i];
		k = 1;
		while(cmp(hold, kb[k]) != -1) k++;
		c.num = c.num + char(k - 1 + '0');
		hold = sub(hold, kb[k - 1]);
	}
	c = hold;
	c.sign = si;
	while(c.num[0] == '0' && c.num.size() > 1) c.num = string(c.num.begin() + 1, c.num.end());
	if(c.num == "0") c.sign = 1;
	return c;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	bigNum a, b;
	cin >> a.num >> b.num;
	a.sign = b.sign = 1;
	bigNum r1, r2 , r3;
	r1.sign = r2.sign = r3.sign = 1;
	r1.num = r2.num = "1";
	while(cmp(r1, b) <= 0){
		if(cmp(r1, a) >= 0) cout << r1.num << endl;
		r3 = add(r1, r2);
		r1 = r2;
		r2 = r3;
	}
}
/*
1 100000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000
*/
