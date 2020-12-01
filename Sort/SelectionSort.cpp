#include<iostream>

using namespace std;

void selectionsort(int *, int size);

int main(){
	int a[] = {5,10,3,68,2,20,53,12,1,98,32};
	int size = sizeof(a)/sizeof(a[0]);
	for(int i = 0; i<size; i++){
		cout<<a[i]<<" ";
	} 
	cout<<endl;
	selectionsort(a, size);
	for(int i = 0; i<size; i++){
		cout<<a[i]<<" ";
	} 
	cout<<endl;
} 
void selectionsort(int *arr, int size){
	int index = 0;
	for(int i = 0; i<size-1; i++){
		index = i;
		for(int j = i+1; j<size; j++){
			if(arr[j]<arr[index]) index = j;
		} 
		int tmp = arr[index];
		arr[index] = arr[i];
		arr[i] = tmp;
	}
}
