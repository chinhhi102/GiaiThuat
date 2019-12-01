#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	scanf("%d",&n);
	while(n--){
		map<string,int>M;
		int m;
		string s;
		scanf("%d",&m);
		for(int i=0;i<m;i++){
			cin.ignore();
			cin>>s;
			M[s]++;
		}
		cout<<M.size()<<endl;
	}
}
