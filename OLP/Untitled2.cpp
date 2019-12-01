#include <iostream>
using namespace std;
int f(int n){

if(n==1||n==2)
return 1;
return f(n-1)+f(n-2);}
int s(int n){
if(n==0){return 0;
}
	

	
	

return s(n-1)+f(n);}
int main(){
	int n;
	cin>>n;
	cout<<"ket qua"<<s(n);
}
