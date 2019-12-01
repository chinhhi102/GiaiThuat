#include<bits/stdc++.h>
using namespace std;
int n,k,m,res(0);
map<int,int>M;
int main(){
    scanf("%d%d",&n,&k);
    while(n--){
    	scanf("%d",&m);
    	M[m%k]++;
	}
	for(map<int,int>::iterator i=M.begin();i!=M.end();i++)res++;
	printf("%d",res);
}
