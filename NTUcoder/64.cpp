#include<bits/stdc++.h>
using namespace std;
struct data{int a,b;};
bool cmp(data x,data y){return (x.a<y.a||(x.a==y.a&&x.b<y.b))?true:false;}
int main(){
	data h[100000];
	long long n,c;
	scanf("%d%d",&n,&c);
	for(int i=0;i<n;i++)scanf("%d%d",&h[i].a,&h[i].b);
	sort(h,h+n,cmp);
	int i=0;
	for(;c>=h[i].a&&i<n;i++)c+=h[i].b;
	printf("%d",i);
}    
