#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    for(int j=0;j<3;j++){
        for(int k=0;k<n;k++)
        for(int l=0;l<3;l++)
        printf(((i+k)%2)?"B":"W");printf("\n");
    }
}
