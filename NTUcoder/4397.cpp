#include<bits/stdc++.h>
using namespace std;
#define int long long
#define fora(i,a,b) for(int i=a;i<b;i++)
struct poker{
	char num,cat;
};
#undef int
int main(int argc, char const *argv[]){
#define int long long
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//    freopen("Electric//00.in","r",stdin);
//    freopen("out.txt","w",stdout);
    poker p[13];
	fora(i,0,13)
		cin>>p[i].num>>p[i].cat;
	multiset<char> m1;
	set<char> m2;
	fora(i,0,13){
		m1.insert(p[i].num);
		m2.insert(p[i].num);
	}
	string tala="3456789TJQKA2";
	if(m2.size()==13||m1.count('2')==4)
		cout<<"YES";
	else{
		int doi=0;
		int l=-1,r=-1;
		fora(i,0,13){
			if(m1.count(tala[i])==2||m1.count(tala[i])==3){
				doi++;
				if(l==-1)
					l=i;
				r=i;
			}
			if(m1.count(tala[i])==4)
				doi+=2;
		}
		if((doi==5&&(r-l)==4)||doi==6)
			cout<<"YES";
		else
			cout<<"NO";
	}
    return 0;
}
