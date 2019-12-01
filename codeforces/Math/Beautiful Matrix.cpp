#include<bits/stdc++.h>
using namespace std;
int main(){
	int a[26];
	for(int i=0;i<25;i++){scanf("%d",&a[i]);if(a[i])printf("%d",abs(2-i/5)+abs(2-i%5));}
}
