#include<bits/stdc++.h>
using namespace std;
#define long long ll;
int main(){
	int a[200050];
	char s[200050];
	bool flag(0);
	int n;
	bool vis[200050]={};
	flag=0;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	scanf("%d",&a[i]);
	scanf("%s",s);
	s[n-1]='0';
	s[n]='\0';
	a[n]=n+1;
	flag=1;
	int l;
	l=0;
	int num=0;
	for(int i=0;i<n;i++){
		if(s[i]=='0'){
			if(a[i]!=i+1&&num==0){
				flag=0;
				break;
			}
			if(num==0){
				l=i+1;
				continue;
			}
			int s=0;
			for(int j=l;j<=l+num;j++){
				if(a[j]<=l+num+1&&a[j]>=l+1)s++;
			}
			if(s!=num+1){
				flag=0;
				break;
			}
			num=0;
			l=i+1;
		}else{
			num++;
		}
	}
	printf(flag?"YES\n":"NO\n");
}
