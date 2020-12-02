#include<iostream>

using namespace std;

void merge(int *, int *);

//O(nlogn)
void mergesort(int *, int);

int main(){
	int a[] = {5,10,3,68,2,20,53,12,1,98,32};
	int size = sizeof(a)/sizeof(a[0]);
	for(int i = 0; i<size; i++){
		cout<<a[i]<<" ";
	}
	cout<<endl;
	mergesort(a, size);
	for(int i = 0; i<size; i++){
		cout<<a[i]<<" ";
	}
	cout<<endl;
} 

void merge(int *arr, int size, int *left, int *right){
	int leftindex = 0;
	int rightindex = 0;
	int arrindex = 0;
	while(leftindex < size/2 && rightindex < size-size/2){
		if(left[leftindex]<right[rightindex]){
			arr[arrindex] = left[leftindex];
			leftindex++;
		}
		else{
			arr[arrindex] = right[rightindex];
			rightindex++;
		}
		arrindex++;
	}
	while(leftindex < size/2){
		arr[arrindex] = left[leftindex];
		leftindex++;
		arrindex++;
	}
	while(rightindex < size-size/2){
		arr[arrindex] = right[rightindex];
		rightindex++;
		arrindex++;
	}
} 

void mergesort(int *arr, int size){
	
	if(size<2) return;
	
	int mid = size/2;
	int *left = new int[mid];
	int *right = new int[size-mid];
	for(int i=0; i<mid; i++){
		left[i] = arr[i];
	}
	for(int i = mid; i<size; i++){
		right[i-mid] = arr[i];
	}
	mergesort(left, mid);
	mergesort(right, size-mid);
	merge(arr, size, left, right);
	delete [] left;
	delete [] right;
}
