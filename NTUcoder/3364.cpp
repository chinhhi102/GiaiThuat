#include<bits/stdc++.h>
using namespace std;
#define int long long
#undef int
int main(int argc, char const *argv[]){
#define int long long
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//    freopen("Electric//00.in","r",stdin);
//    freopen("out.txt","w",stdout);
    int sum=0;
    string s;
    cin>>s;
    map<char,int>m;
    m['I']=1;
    m['V']=5;
    m['X']=10;
    m['L']=50;
    m['C']=100;
    m['D']=500;
    m['M']=1000;
    for(int i=0;i<s.size();i++)
		sum+=m[s[i]]-(m[s[i-1]]<m[s[i]]?m[s[i-1]]*2:0);
    cout<<sum;
	return 0;
}

