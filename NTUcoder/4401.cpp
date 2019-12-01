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
	int sum=0;
    cin>>s;
    for(int i=0;i<s.size();i++)sum+=s[i]-'0';
    while(sum>9){
        int temp=sum%10;        
        while(sum/=10){
            temp+=sum%10;
        }
        sum=temp;
    }
    cout<<sum;
	return 0;
}

