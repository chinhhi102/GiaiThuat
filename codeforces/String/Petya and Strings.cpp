#include<string.h>
#include<stdio.h>
	int s1=0,s2=0;
	char st1[101],st2[101];
int main(){
	scanf("%s%s",st1,st2);
	strlwr(st1);strlwr(st2);
	if(strcmp(st1,st2)<0)printf("-1");else printf("%d",strcmp(st1,st2)?1:0);
}
