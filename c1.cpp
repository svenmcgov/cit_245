// Stephen McGovern CIT-245
// 01/04/17

#include <iostream>
using namespace std;

int main(){
	
	bool continueFlag = true;
	double input;
	double guess;
	double lastGuess;
	double r;
	double percentDiff = 0.0; // use a do while for computations loop.  post check will allow the percentDiff to be reset appropriately
	
	
	while(continueFlag){
		cout << "Enter a number and I will apply the Babylonian square root algorithm\nuntil I am within .001 percent of the correct answer.\n";
	
		cin >> input;
		guess = input / 2;
		lastGuess = guess;
	
		do{
			r = input/guess;
			guess = (guess + r) / 2;
			percentDiff = (lastGuess - guess) / guess;
			lastGuess = guess; // reassign for next iteration
			cout << guess << "\n";
			cout << "Percent change: " << percentDiff << "\n";
		
		}while(percentDiff > .001);
	
	
		cout << "The Babylonian algorithm gives: " << guess << "\n";
		cout << "Checking: " << guess << " * " << guess << " = " << guess * guess << "\n";
		
		char promptAnswer;
		
		while(continueFlag){
			cout << "Try another number?  y/n : ";
			cin >> promptAnswer;
			if(promptAnswer == 'y' || promptAnswer == 'Y'){
				break; // return to outer while with continueFlag still set to true
			}else if(promptAnswer == 'n' || promptAnswer == 'N'){
				continueFlag = false; // end the program
			}else{
				cout << "Unable to recognize response.\n"; // ask for y/n again
			}
		}
	}
	return 0;
}
