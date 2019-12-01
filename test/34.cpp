#include<bits/stdc++.h>
#include<conio.h>
#define max 256
#include<stdio.h>
using namespace std;
char *trichchuoi(char s[],int pos,int len)
{
	char kq[100]="";
	int j=0;
	for (int i=pos;i<pos+len;i++){
		kq[j]=s[i];
		j++;
	}
	return kq;
}
int main(){
	int pos,len;
	char s[50];
	cout<<"NHap chuoi ki tu ";gets(s);
	cout<<"NHap vi tri ";cin>>pos;
	cout<<"So ki tu ";cin>>len;
	puts(trichchuoi(s,pos,len));
	return 0;
}
