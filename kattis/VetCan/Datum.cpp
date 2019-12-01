#include<bits/stdc++.h>
using namespace std;
#define if(a) if(Month==a)
int main(){
	string Doom[7]={"Saturday","Sunday","Monday","Tuesday","Wednesday","Thursday","Friday"};
	int Month,Day;
	scanf("%d%d",&Day,&Month);
	if(2){cout<<Doom[Day%7];return 0;}
	if(3){cout<<Doom[Day%7];return 0;}
	if(11){cout<<Doom[Day%7];return 0;}
	if(8){cout<<Doom[(Day+6)%7];return 0;}
	if(5){cout<<Doom[(Day+5)%7];return 0;}
	if(10){cout<<Doom[(Day+4)%7];return 0;}
	if(1){cout<<Doom[(Day+4)%7];return 0;}
	if(4){cout<<Doom[(Day+3)%7];return 0;}
	if(7){cout<<Doom[(Day+3)%7];return 0;}
	if(12){cout<<Doom[(Day+2)%7];return 0;}
	if(9){cout<<Doom[(Day+2)%7];return 0;}
	if(6){cout<<Doom[(Day+1)%7];return 0;}
}
