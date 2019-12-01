#include<bits/stdc++.h>
using namespace std;
typedef string bigNum;
bigNum add(bigNum a,bigNum b){
	while(a.size()<b.size()) a='0'+a;
	while(b.size()<a.size()) b='0'+b;
	bigNum c = "";
	int carry = 0, s;
	for(int i=a.size()-1;i>=0;i--){
		s = (a[i] - '0') + (b[i] - '0') + carry;
		carry = (s >= 10);
		c = char(s % 10 + '0') + c;
	}
	if(carry)
		c = "1" + c;
	return c;
}

bigNum Fibo(int n){
	int i;
	bigNum fi_1,fi_2,fi;
	if(n <= 1)
		return "1";
	fi_1 = "1";
	fi_2 = "0";
	for(int i=2;i<=n;i++){
		fi = add(fi_1,fi_2);
		fi_2 = fi_1;
		fi_1 = fi;
	}
	return fi;
}

int main(){
	int N;
	cout << "Nhap N: ";
	cin >> N;
	cout << Fibo(N);
//	printf("Nhap N: ");
//	scanf("%d",&N);
//	printf("%s\n",Fibo(N));
}
