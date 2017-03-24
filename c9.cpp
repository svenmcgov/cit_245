// Stephen McGovern CIT-245
// 02/27/17

#include <iostream>
#include <string>
#include <cstdio>
#include <stdlib.h>
#include <stack>
using namespace std;

string getInput();
// no args.  prompts user for input
// returns their response

void loadStack(char* letters, stack<char>& letterStack);
// loads character input into a stack
// passed stack by reference

void stackPrint(stack<char>& letterStack);
// output and empty a stack.  need to 'pop' the top element to access the next one.
// due to the nature of the stack, it will be the desired reverse order (last in, first out)

bool continueCheck();
// control for loop.  prompts user if they want to continue
// returns true or false based on response



int main(){
	
	cout << "\nThis program reverses a string using the STL stack." << endl;
	char* char_array = (char*)malloc(80); // moved declaration outside loop
	stack<char> char_stack; 
	
	do{
		cout << "Enter your string of less than 80 characters followed by an ENTER." << endl;
		cin.getline(char_array,81,'\n');
		loadStack(char_array, char_stack);
		stackPrint(char_stack);
		
	}while(continueCheck());
	
	free (char_array); // found 'free' online to free up allocated memory...
					   // compile OK on g++ Ubuntu 5.4.0
}
	
void loadStack(char* letters, stack<char>& letterStack){
	int i = 0;
	while(letters[i] != '\0'){ // page 376, '\0' terminates C string
		letterStack.push(letters[i]);
		i++;
	}
}

void stackPrint(stack<char>& letterStack){
	while(!letterStack.empty()){
		cout << letterStack.top();
		letterStack.pop(); // remove top element to access the next one
	}
	cout << endl;
}

bool continueCheck(){
	char response;
	
	while(true){
	
		cout << "Try again with more input? y/n ";
		cin >> response;
	
		if(response == 'y' || response == 'Y'){
			getchar(); // clear the '\n'
			return true;
		}else if (response == 'n' || response == 'N'){
			break;
		}else{
			cout << "Did not recognize response.\n";
		}
	}
	return false;
}

