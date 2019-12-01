#include<bits/stdc++.h>
using namespace std;
int main(){
	string s;int o=0,m(11);
	cin>>s;
	int num=s.size(),t(5);
	while(t--){
		bool flag(0);
		if(t==4||!t)
		for(int i=1;i<=1+4*num;i++){
			if(i==m){printf("*");flag=0;m+=12;}
			else if(i%2&&flag){
				printf("#");
				flag=0;
			}else{
				printf(".");if(i%2)flag=1;
			}
		}
		if(t==3||t==1)
		for(int i=1;i<=1+4*num;i++){
			if(i==m-1||i==m+1){printf("*");flag=0;if(i==m+1)m+=12;}
			else if(!(i%2)&&flag){
				printf("#");
				flag=0;
			}else{
				printf(".");flag=1;
			}
		}
		if(t==2)
		for(int i=1;i<=1+4*num;i++){
			if((3+4*o)==i){printf("%c",s[o++]);flag=1;}
			else if(i==m-2||i==m+2){if(num%3==2&&i==m-2&&i==1+4*num)printf("#");else printf("*");flag=1;if(i==m+2)m+=12;}
			else if(!(i%2)&&flag){
				printf(".");
				flag=0;
			}else{
				printf("#");flag=1;
			}
		}
	m=11;
	if(t)printf("\n");
	}
}
