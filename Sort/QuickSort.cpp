#include<iostream>

using namespace std;

int partition(int *, int start, int end);
//O(n^2)
void quicksort(int *, int start, int end);

int main(){
	int a[] = {5,10,3,68,2,20,53,12,1,98,32};
	int size = sizeof(a)/sizeof(a[0]);	
	for(int i = 0; i<size; i++){
		cout<<a[i]<<" ";
	}
	cout<<endl;
	quicksort(a, 0, 10);
	for(int i = 0; i<size; i++){
		cout<<a[i]<<" ";
	}
	cout<<endl;
} 

int partition(int *arr, int start, int end){
	int pivot = arr[end];
	int pindex = start;
	for(int i = start; i < end; i++){
		if(arr[i]<=pivot){
			int temp = arr[i];
			arr[i] = arr[pindex];
			arr[pindex] = temp;
			pindex = pindex + 1;
		}
	}
	int temp = arr[end];
	arr[end] = arr[pindex];
	arr[pindex] = temp;
	return pindex;
}

void quicksort(int *arr, int start, int end){
	if(start<end){
		int pivot = partition(arr, start, end);
		quicksort(arr, start, pivot-1);
		quicksort(arr, pivot+1, end);
	}
	
}
