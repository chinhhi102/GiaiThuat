#include<bits/stdc++.h>
using namespace std;
//void in(int x,int n){
//	int arr[n]={};
//	int id=0;
//	while(x>0){
//		arr[id]=x%2;
//		x >>= 1;
//		id++;
//	}
//	for(int i=n-1;i>=0;i--)
//		cout<<arr[i];
//	cout<<endl;
//}
int main(){
	// logic la toan tu so sanh giua 2 kdl la bool
	// = 0 -> false != 0 -> true
	// a = 1110 = 14
	// a >> 2
	// a = 0011 = 3
	// a >> 1
	// a = 0001 = 1
	// a = 0100
	// 1 << n -> 2^n
	int i, j;
   
   i = 10;
   i = (i++, i+100, 999+i);

   cout << i;
}
