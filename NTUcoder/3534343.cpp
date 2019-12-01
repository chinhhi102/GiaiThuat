#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin>>n;
	int c=0, l=0, k=0, snt=0, scp=0, temp;
	while (n!=0){
		temp=n%10;
		n/=10;
		if (temp%2==0) c++;
			else l++;
		if (temp==0) k++;
		if ((int)sqrt(temp)==(float)sqrt(temp)) scp++;
		bool kt=true;
		if (temp<2) kt=false;
		else 
		for (int i=2; i<=sqrt(temp); i++){
			if (temp%i==0){
				kt=false;
				break;
			}
		}
		if (kt) snt++;
	}
	cout<<"Co "<<c<<" so chan!"<<endl;
	cout<<"Co "<<l<<" so le!"<<endl;
	cout<<"Co "<<k<<" so khong!"<<endl;
	cout<<"Co "<<snt<<" so nguyen to!"<<endl;
	cout<<"Co "<<scp<<" so chinh phuong!"<<endl;
	return 0;
}
