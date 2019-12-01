#include<bits/stdc++.h>
using namespace std;
int n,arr[20];
void xuat(){
	for(int i=0;i<n;i++)
		cout<<arr[i];
	cout<<endl;
}
void tohop(int id){
	if(id==n){
		cout<<"Xuat: ";
		xuat();
		system("pause");
	}else{
		for(int i=1;i<=n;i++){
			arr[id]=i;
			cout<<"id = "<<id<<"\ni = "<<i<<"\narr["<<id<<"] = " << arr[id]<<endl;
			system("pause");
			tohop(id+1);
		}
	}
}
int main(){
	cin>>n;
	tohop(0);
}
