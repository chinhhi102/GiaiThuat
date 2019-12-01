#include<bits/stdc++.h>
using namespace std;
#define int long long
#undef int
int main(int argc, char const *argv[]){
#define int long long
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//    freopen("Electric//00.in","r",stdin);
//    freopen("out.txt","w",stdout);
    string s;
	int dem=0;
	cin>>s; 	
 	for(int i=0;i<s.size();i++){
 		if((!i||s[i-1]=='.')&&s[i]!='.')
			dem++;
	}
	cout<<dem;
	return 0;
}
