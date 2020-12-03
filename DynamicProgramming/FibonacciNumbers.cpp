#include<iostream> 
#include<ctime>

using namespace std;

int arr[1000];
int Fib_recur(int num);
int Fib_dyna(int num);

int main(){
	for(int i=0; i<1000; i++) arr[i] = 0;
	int firstnum, secondnum;
	int answer_first = 0;
	int answer_second = 0;
	clock_t start, end;
	cout<<"Enter a number:";
	cin>>firstnum;
	
	start = clock();
	answer_first = Fib_recur(firstnum);
	cout<<"First answer: "<<answer_first<<endl;
	end = clock();
	cout<<"Time: "<<double(end-start)/CLOCKS_PER_SEC<<endl<<"-------------------"<<endl;
	
	cout<<"Enter a number:";
	cin>>secondnum;
	
	start = clock();
	answer_second = Fib_dyna(secondnum);
	cout<<"Second answer: "<<answer_second<<endl;
	end = clock();
	cout<<"Time: "<<double(end-start)/CLOCKS_PER_SEC<<endl<<"-------------------"<<endl;
}

int Fib_recur(int num){
	if(num == 1) return 1;
	if(num == 2) return 1;
	return Fib_recur(num - 1) + Fib_recur(num - 2);
}

int Fib_dyna(int num){
	if(num == 1) return 1;
	if(num == 2) return 1;
	if(arr[num]!=0) return arr[num];
	arr[num] = Fib_dyna(num-1) + Fib_dyna(num-2);
	return arr[num];
}
