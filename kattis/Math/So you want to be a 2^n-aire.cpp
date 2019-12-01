#include<bits/stdc++.h> 
using namespace std;
double res(int n, double t){
	double f=pow(2,n);
	double eq,prize;
	for (int i=n-1;i>=0;i--){
		prize=pow(2,i);
		eq=prize/f;
		if (eq<=t)
			f=(t+1)/2*f;
		else
			f=(eq-t)/(1-t)*prize+(1-eq)/(1-t)*(eq+1)/2*f;
	}
	return f;
}
int main(){
	int n;
	double t;
	while (scanf("%d %lf",&n,&t)){
		if(n==0&&(int)t==0)break;
		printf("%.3lf\n",res(n,t));
	}
}





#include<bits/stdc++.h>
using namespace std;
int n;
double r;
double res(int q,double money){
	if(q==n)return money;
	double ret=0;
	double a=res(q+1,money*2);
	double eq=money/a;
	if(eq>r)ret+=money*(eq-r)+(1-eq*eq)/2*a;
	else ret+=(1-r*r)/2*a;
	ret/=(1-r);
	return ret;
}
int main(){
	while(scanf("%d%lf",&n,&r)){
		if(n==0&&(int)r==0)break;
		(fabs(r-1)<1e-7)?printf("%.3lf\n",pow(2,n)):printf("%.3lf\n",res(0,1));
	}
}
