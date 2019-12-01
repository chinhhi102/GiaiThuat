#include<bits/stdc++.h>
using namespace std;
int partition(int arr[], int l, int r){
	int p=arr[r], i=l-1;
	for(int j=l;j<r;j++)
		if(arr[j]<p)
			swap(arr[++i],arr[j]);
	swap(arr[++i],arr[r]);
	return i;
}
void quickSort(int arr[], int l, int r){
	if(l<r){
		int p = partition(arr,l,r);
		quickSort(arr,l,p-1);
		quickSort(arr,p+1,r);
	}
}
int main(){
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++)
		cin>>arr[i];
	quickSort(arr,0,n-1);
	for(int i=0;i<n;i++)
		cout<<arr[i]<<' ';
}
/*
10
4 10 3 5 1 2 3 4 5 6
*/
