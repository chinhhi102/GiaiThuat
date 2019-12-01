#include<bits/stdc++.h>
using namespace std;
#define int long long

#undef int
int main(){
#define int long long
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	ifstream f1("res.txt");
	ifstream f2("TESTINCPOS\\04.out");
	string s1,s2;
	int d=1;
	while(getline(f1,s1)&&getline(f2,s2)){
		if(s1!=s2)
			cout<<"Wrong answer at test "<<d++<<endl;
		else
			cout<<"Test "<<d++<<" Corect"<<endl;
	}
	return 0;
}
