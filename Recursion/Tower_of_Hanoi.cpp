#include<iostream>

using namespace std;

void hanoi(int , char, char, char);

int main(){
	int number;
	cout<<"Enter a number: ";
	cin>>number;
	hanoi(number, 'A', 'B', 'C');
} 

void hanoi(int num, char a, char b, char c){
	if(num == 1) cout<<"move "<<a<<" to "<<c<<endl;
	else{
		hanoi(num-1, a, c, b);
		hanoi(1, a, b, c);
		hanoi(num-1, b, a, c);
	}
}
