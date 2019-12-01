#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    while(cin>>n){
        cin.ignore();
        string s;
        getline(cin,s);
        string temp="";
        string backslashes;
        backslashes.resize(pow(2,n)-1,'\\');
        for(int i=0;i<s.size();i++){
            if(('!'<=s[i]&&s[i]<='*')||('['<=s[i]&&s[i]<=']')){
                temp+=backslashes;
            }
            temp.push_back(s[i]);
        }
        cout<<temp<<endl;
    }
}
