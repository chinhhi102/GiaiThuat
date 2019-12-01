#include<stdio.h>
int main(){
    double a,b;
    scanf("%lf%lf",&a,&b);
    long long x=a>(long long)?a+1:a,y=(long long)b;
    printf("%lld",(x+y)*(y-x+1)/2);
    return 0;
}
