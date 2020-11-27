#include<iostream>

using namespace std;

//O(n^2)
void bubblesort(int *, int);
int main(){
	int a[] = {5,10,3,68,2};
	int size = sizeof(a)/sizeof(a[0]);
	
	for(int i=0;i<size;i++){
		cout<<a[i]<<" ";
	}
	cout<<endl;
	bubblesort(a,size);
	for(int i=0;i<size;i++){
		cout<<a[i]<<" ";
	}
	cout<<endl;
} 

void bubblesort(int *arr, int size){
	for(int i=0;i<size-1;i++){
		for(int j=0;j<size-1-i;j++){	
			if(arr[j]>arr[j+1]){
				int tmp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = tmp;
			}
		}
	}
}
