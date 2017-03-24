
#include <iostream>
using namespace std;

void fillArray(int a[], int size);

bool search(int a[], int size, int target);

void output(int a[], int size);

bool continueCheck();

int main(){
	
	int size;
	int *numbers;
	
	do{
		cout << "How many numbers would you like in the array? ";
		cin >> size;
		numbers = new int[size];
	
		fillArray(numbers, size);
		output(numbers, size);
	
		int target;
		cout << "Which number would you like to check for? ";
		cin >> target;
		
	
		if(search(numbers, size, target)){
			cout << target << " is in the array." << endl;
		}else{
			cout << target << " is not in the array." << endl;
		}
	}while(continueCheck());
	
	return 0;
}

void fillArray(int a[], int size){
	cout << "Please enter " << size << " integers: ";
	for(int i = 0; i < size; i++){
		cin >> a[i];
	}
}

bool search(int a[], int size, int target){
	int index = 0;
	while(index < size){
		if(a[index] == target)
			return true;
		index++;
	}
	return false;
}

void output(int a[], int size){
	cout << "Your numbers are:" << endl;
	for(int i = 0; i < size; i++)
		cout << a[i] << " ";
	cout << endl;
}

bool continueCheck(){
	char ans;
	while(true){
		cout << "Try again? y/n ";
		cin >> ans;
		if(ans == 'y' || ans == 'Y'){
			return true;
		}else if (ans == 'n' || ans == 'N'){
			break;
		}else{
			cout << "Did not recognize response." << endl;
		}
	}
	return false;
}
