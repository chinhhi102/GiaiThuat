#include <iostream>
#include <bits/stdc++.h>

using namespace std;
long a[100001],i,n;
void qs(long h,long k)
{
    long i=h,j=k,x=a[(h+k)/2];
    while (i<=j)
    {
        while (a[i]<x) i++;
        while (x<a[j]) j--;
        if (i<=j)
        {
            swap(a[i],a[j]);
            if (i!=j) cout << i<< " " << j << endl;
               i++;j--;
        }

    }
    if (h<j) qs(h,j);
    if (i<k) qs(i,k);
}
int main()
{
    cin>>n;
    for (long i=1;i<=n;i++)
    cin>>a[i];
    qs(1,n);
}
