#include<bits/stdc++.h>
using namespace std;
void updateHeap(int arr[], int n, int i){
	int largest = i, l = i*2+1, r = l + 1;
	if(l < n && arr[largest] < arr[l])
		largest = l;
	if(r < n && arr[largest] < arr[r])
		largest = r;
	if(largest != i){
		swap(arr[i], arr[largest]);
		updateHeap(arr, n, largest);
	}
}
void heapSort(int arr[],int n){
	for(int i=n/2-1;i>=0;i--)
		updateHeap(arr, n, i);
	for(int i=n-1;i>=0;i--){
		swap(arr[i], arr[0]);
		updateHeap(arr, i, 0);
	}
}
int main(){
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++)
		cin>>arr[i];
	heapSort(arr,n);
	for(int i=0;i<n;i++)
		cout<<arr[i]<<' ';
}
/*
10
4 10 3 5 1 2 3 4 5 6
*/
