#include<iostream>
#include<ctime>

using namespace std;

void bubblesort(int *, int);
void selectionsort(int *, int);
void insertionsort(int *, int);
void mergesort(int *, int);
void merge(int *, int, int *, int *);
void quicksort(int *, int, int);
int partition(int *, int, int);

int main(){
	int a[] = {5,10,3,68,2,20,53,12,1,98,32};
	int size = sizeof(a)/sizeof(a[0]);
	clock_t start, end;
	
	cout<<"Bubble Sort:"<<endl;
	for(int i=0;i<size;i++) cout<<a[i]<<" ";
	cout<<endl;
	
	start = clock();
	bubblesort(a, size);
	end = clock();
	
	for(int i=0;i<size;i++) cout<<a[i]<<" ";
	cout<<endl<<"Time: "<<double(end-start)*1000000<<endl;
	cout<<endl<<"----------------------------"<<endl<<endl;
	
	int b[] = {5,10,3,68,2,20,53,12,1,98,32};
	cout<<"Selection Sort:"<<endl;
	for(int i=0;i<size;i++) cout<<b[i]<<" ";
	cout<<endl;
	
	start = clock();
	selectionsort(b, size);
	end = clock();
	
	for(int i=0;i<size;i++) cout<<b[i]<<" ";
	cout<<endl<<"Time: "<<double(end-start)<<endl;
	cout<<endl<<"----------------------------"<<endl<<endl;
	
	int c[] = {5,10,3,68,2,20,53,12,1,98,32};
	cout<<"Insertion Sort:"<<endl;
	for(int i=0;i<size;i++) cout<<c[i]<<" ";
	cout<<endl;
	
	start = clock();
	insertionsort(c, size);
	end = clock();
	
	for(int i=0;i<size;i++) cout<<c[i]<<" ";
	cout<<endl<<"Time: "<<double(end-start)<<endl;
	cout<<endl<<"----------------------------"<<endl<<endl;
	
	int d[] = {5,10,3,68,2,20,53,12,1,98,32};
	cout<<"Merge Sort:"<<endl;
	for(int i=0;i<size;i++) cout<<d[i]<<" ";
	cout<<endl;
	
	start = clock();
	mergesort(d, size);
	end = clock();
	
	for(int i=0;i<size;i++) cout<<d[i]<<" ";
	cout<<endl<<"Time: "<<double(end-start)<<endl;
	cout<<endl<<"----------------------------"<<endl<<endl;
	
	int e[] = {5,10,3,68,2,20,53,12,1,98,32};
	cout<<"Quick Sort:"<<endl;
	for(int i=0;i<size;i++) cout<<e[i]<<" ";
	cout<<endl;
	
	start = clock();
	quicksort(e, 0, size-1);
	end = clock();
	
	for(int i=0;i<size;i++) cout<<e[i]<<" ";
	cout<<endl<<"Time: "<<double(end-start)<<endl;
	cout<<endl<<"----------------------------"<<endl<<endl;
	
} 

//O(n^2)
void bubblesort(int *arr, int size){
	for(int i=0;i<size-1;i++){
		for(int j=0;j<size-i-1;j++){
			if(arr[j]>arr[j+1]){
				int temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
			}
		} 
	}
}

//O(n^2)
void selectionsort(int *arr, int size){
	for(int i=0;i<size-1;i++){
		int index = i;
		for(int j=i;j<size;j++){
			if(arr[j]<arr[index]) index = j;
		}
		int temp = arr[i];
		arr[i] = arr[index];
		arr[index] = temp;
	}
}

//O(n^2)
void insertionsort(int *arr, int size){
	for(int i=0;i<size-1;i++){
		for(int j=i+1;j>0;j--){
			if(arr[j]<arr[j-1]){
				int temp = arr[j];
				arr[j] = arr[j-1];
				arr[j-1] = temp;
			}
		}
	}
}

//O(nlogn)
void mergesort(int *arr, int size){
	
	if(size<2) return;
	
	int *left = new int[size/2];
	int *right = new int[size-size/2];
	for(int i=0;i<size/2;i++) left[i] = arr[i];
	for(int i=size/2;i<size;i++) right[i-size/2] = arr[i];
	mergesort(left, size/2);
	mergesort(right, size-size/2);
	merge(arr, size, left, right);
	delete [] left;
	delete [] right;
}

void merge(int *arr, int size, int *left, int *right){
	int leftindex = 0;
	int rightindex = 0;
	int index = 0;
	while(leftindex<size/2 && rightindex<size-size/2){
		if(left[leftindex]<right[rightindex]){
			arr[index] = left[leftindex];
			leftindex++;
		}
		else{
			arr[index] = right[rightindex];	
			rightindex++;
		}
		index++;
	}
	while(leftindex<size/2){
		arr[index] = left[leftindex];
		leftindex++;
		index++;
	}
	while(rightindex<size-size/2){
		arr[index] = right[rightindex];	
		rightindex++;
		index++;
	}
}

void quicksort(int *arr, int left, int right){
	if(left<right){
		int pivot = partition(arr, left, right);
		quicksort(arr, left, pivot-1);
		quicksort(arr, pivot+1, right);
	}
}

int partition(int *arr, int left, int right){
	int pivot = arr[right];
	int index = left;
	for(int i=left; i<right; i++){
		if(arr[i]<pivot){	
			int temp = arr[i];
			arr[i] = arr[index];
			arr[index] = temp;
			index++;
		}
	}
	int temp = arr[index];
	arr[index] = arr[right];
	arr[right] = temp;
	return index;
}
