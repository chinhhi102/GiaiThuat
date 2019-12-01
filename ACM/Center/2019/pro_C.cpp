#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin>>n;
	int x1,x2,y1,y2;
	for(int i=0;i<n;i++){
		cin>>x1>>y1>>x2>>y2;
		int d1=__gcd(abs(x1),abs(y1));
		int d2=__gcd(abs(x2),abs(y2));
//		cout<<d1<<' '<<d2<<endl;
		if(d1==d2)
			cout<<"YES"<<endl;
		else
			cout<<"NO"<<endl;
	}
}
