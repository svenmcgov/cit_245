#include <iostream>
using namespace std;

void printVertical(int i);
// takes int i as an argument
// prints vertically

int main(){
	cout << "Testing..." << endl;
	cout << "Enter a number to be printed vertically" << endl;
	
	int input;
	cin >> input;
	printVertical(input);
}

void printVertical(int i){
	if(i < 10){
		cout << i << endl;
	}else{
		
		printVertical(i/10);
		cout << i % 10 << endl;
	}
}
