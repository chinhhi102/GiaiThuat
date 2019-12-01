#include<iostream>
using namespace std;
int main(){
	int n;
	cin>>n;
	int s[n],m[n]={1};
	for (int i = 0; i < n; i++)
		cin>>s[i];
	for (int i = 1; i < n; i++){
		for (int j = 0; j < i; j++){
			if (s[i] > s[j] && m[j]>=m[i]){
					m[i]=m[j]+1;
				}
			if (m[i]==0)
				m[i]=1;
		}		
	}
	int t=1;
	for (int i = 0; i < n; i++)
		if (m[t] < m[i]){	
			t = i;
		}
	cout<<m[t]<<endl;
	for (int i = 0; i <= t; i++){
		if (s[i] < s[t] && s[i]<s[i+1])
			cout<<s[i]<<" ";
	}
	cout<<s[t];
	return 0;
}
