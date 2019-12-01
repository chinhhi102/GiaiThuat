#include<bits/stdc++.h>
using namespace std;
void merge(int arr[], int l, int m, int r){
	int narr[] = arr;
	int n1 = m - l + 1;
	int n2 = r - m;
	int k = l, i = 0, j = 0;
	while(i<n1 && j < n2){
		if(narr[l+i] < narr[m+j+1])
			arr[k++]=narr[l+i++];
		else
			arr[k++]=narr[m+1+j++];
	}
	while(i<n1)
		arr[k++]=narr[l+i++];
	while(j<n2)
		arr[k++]=narr[m+1+j++];
}
void mergeSort(int arr[], int l, int r){
	if(l<r){
		int m = l+(r-l)/2;
		mergeSort(arr,l,m);
		mergeSort(arr,m+1,r);
		merge(arr,l,m,r);
	}
}
int main(){
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++)
		cin>>arr[i];
	mergeSort(arr,0,n-1);
	for(int i=0;i<n;i++)
		cout<<arr[i]<<' ';
}
/*
10
4 10 3 5 1 2 3 4 5 6
*/
