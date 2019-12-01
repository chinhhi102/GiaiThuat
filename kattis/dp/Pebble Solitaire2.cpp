#include <bits/stdc++.h>
#define fora(i,a,b) for(int i=a;i<b;i++)
using namespace std;
void solve();
int solve(unordered_map<string, int>& memo,string s){
    if(memo.count(s)){
        return memo[s];
    }
    int dots=0;
    for(auto i:s){
        if(i=='o'){
            dots++;
        }
    }
    fora(i,0,s.size()-2){
        if(s[i]=='o'&&s[i+1]=='o'&&s[i+2]=='-'){
            s[i]='-';
            s[i+1]='-';
            s[i+2]='o';
            dots=min(dots,solve(memo,s));
            s[i]='o';
            s[i+1]='o';
            s[i+2]='-';
        }
    }
    fora(i,0,s.size()-2){
        if(s[i]=='-'&&s[i+1]=='o'&&s[i+2]=='o'){
            s[i]='o';
            s[i+1]='-';
            s[i+2]='-';
            dots=min(dots,solve(memo,s));
            s[i]='-';
            s[i+1]='o';
            s[i+2]='o';
        }
    }
    memo[s]=dots;
    return dots;
}
int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    solve();
    return 0;
}

void solve(){
    int n;
    cin>>n;
    unordered_map<string,int> memo;
    while(n--){
        string s;
        cin>>s;
        cout<<solve(memo,s)<<endl;
    }
}
