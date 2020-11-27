#include<iostream>

using namespace std;

//O(n^2)
void InsertionSort(int *, int);
int main(){
	
	int a[] = {5,10,3,68,2};
	int size = sizeof(a)/sizeof(a[0]);
	for(int i=0;i<size;i++){
		cout<<a[i]<<" ";
	}
	cout<<endl;
	InsertionSort(a, size);
	for(int i=0;i<size;i++){
		cout<<a[i]<<" ";
	}
	cout<<endl;
} 

void InsertionSort(int *arr, int size){
	
	for(int i=1; i<size; i++){
		for(int j=i; j>0; j--){
			if(arr[j]<arr[j-1]){
				int temp = arr[j];
				arr[j] = arr[j-1];
				arr[j-1] = temp;
			} 
		}
	}
}
