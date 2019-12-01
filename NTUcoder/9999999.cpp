#include<bits/stdc++.h>
using namespace std;
	int a[20];
	int n;
void backtracking(int id){
	for(int i=0; i<2;i++){
		a[id]=i;
		if(id+1==n){
			for(int j=0; j<n; j++)
				cout << a[j];
			cout<<endl;
		}
		else backtracking(id + 1);
	}
	
}
int main(){
	cin>>n;
	backtracking(0);
	
	
	return 0;
}
