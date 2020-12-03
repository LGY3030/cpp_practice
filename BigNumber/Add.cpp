#include<iostream>
#include <algorithm>

using namespace std;

int main(){
	string a, b;
	cout<<"Enter two numbers: ";
	cin>>a>>b;
	
	reverse(a.begin(), a.end());
	reverse(b.begin(), b.end());
	
	int k = max(a.size(), b.size());
	string c(k+1, ' ');
	
	for(int i=0; i<k; i++){
		int a_v = 0;
		int b_v = 0;
		if(a.size()>=i) a_v = a[i]-'0';
		if(b.size()>=i) b_v = b[i]-'0';
		c[i] = (a_v + b_v)%10 + '0'; 
		c[i+1] = (a_v + b_v)/10 + '0';
	}
	
	reverse(b.begin(), b.end());
	
	cout<<"Answer: "<<c;
}
