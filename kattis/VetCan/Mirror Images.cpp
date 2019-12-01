#include<bits/stdc++.h>
using namespace std;
string flip(string s,int m){
	string re="";
	for(int i=m-1;i>=0;i--){
		re+=s[i];
	}
	return re;
}
int main(){
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		int d,k;
		scanf("%d%d",&d,&k);
		string res[d];
		cin.ignore();
		printf("Test %d\n",i+1);
		for(int i=0;i<d;i++){
			getline(cin,res[i]);
			res[i]=flip(res[i],k);
		}
		for(int i=d-1;i>=0;i--)cout<<res[i]<<endl;
	}
}
