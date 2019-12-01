#include<bits/stdc++.h>
using namespace std;
#define int long long
#undef int
int main(int argc, char const *argv[]){
#define int long long
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//    freopen("Electric//00.in","r",stdin);
//    freopen("out.txt","w",stdout);
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
    	for(int j=0;j<n;j++)
    		cout<<((i+j)%2?'B':'W');
    	cout<<endl;
    }
    return 0;
}
