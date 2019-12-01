#include <iostream>
#include <math.h>

using namespace std;

long long binomial(int x,int n,int k){

    int i;
    long long int answer=0;
    double aux=1;

    for(i=1;i<=n;i++){

            aux*=(float)x+1-i;
            aux/=(float)i;
            answer+=aux;

            if(answer>k) break;
    }

    return answer;
}

int main()
{
    int n;
    int k;
	int T;
	cin>>T;
	while(T--){
    cin>>k;

    cin>>n;


    int mid,upper,inf;

    upper=k;
    inf=0;
    mid=(upper+inf)/2;

    while(upper-inf>1){
        mid=inf+(upper-inf)/2;
        if(binomial(mid,n,k)<k) inf=mid;
        else upper=mid;

    }

    inf>32?cout<<"Impossible":cout<<inf+1;cout<<endl;
	}
}
