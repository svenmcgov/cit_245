// Stephen McGovern CIT-245
// 02/07/17

#include <iostream>
#include <cstdlib>
#include <cmath>

using namespace std;

int diceRoll(int min, int max);
// returns an int between min and max
int prompt();
// prompts the user for the number of trials
// they wish to run - returns an int
bool continuePrompt();
// checks if the user wants to continue
// returns true or false
void outputResults(int dieTotalCounts[], int arraySize, int numberOfTrials);
// takes in the array holding the counts for each die roll total, the size of that array
// and the number of Trails run.  no return - prints formatted output of totals info
double calculateError(int numberRolled, int odds);
// calculates error percent given the total number rolled for a sum and the odds of it being rolled
void setToZero(int dieTotalCounts[], int arraySize);
// sets int array value to zeroes
// use to reset array in main loop

int main(){
	int rollTotal = 0;
	int numberOfTrials = 0;
	const int TOTALS = 11; // array size, 11 different possible TOTALS
	int dieTotalCounts[TOTALS]; // arrays chapter 5
	
	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.precision(4);
	
	cout << "This program rolls two dice and tabulates the results\n\n";
	srand(time(NULL));
	
	do{
		numberOfTrials = prompt();
		setToZero(dieTotalCounts, TOTALS);
		for(int i = 0; i < numberOfTrials; i++){
			rollTotal = diceRoll(1, 6) + diceRoll(1, 6);
			dieTotalCounts[rollTotal - 2] += 1; // need to subtract 2 from rollTotal
												// this is so 2's go into index 0, 3's into 1, etc.
		}
		outputResults(dieTotalCounts, TOTALS, numberOfTrials);
	
	}while(continuePrompt());
}

int diceRoll(int min, int max){
	return min + (rand() % (max - min + 1));
}

int prompt(){
	cout << "Please enter the number of rolls you want: ";
	int ans = 0;
	cin >> ans;
	return ans;
}

bool continuePrompt(){
	while(true){
		char ans;
		cout << "Try again? y/n ";
		cin >> ans;
		if(ans == 'y' || ans == 'Y'){
			break;
		}else if(ans == 'n' || ans == 'N'){
			return false;
		}else{
			cout << "Did not recognize response\n";
		}	
	}
	return true;
}

void outputResults(int dieTotalsCount[], int arraySize, int numberOfTrials){
	
	// would have put everything that has to do with odds in its own function
	// but need to get to chapter 10 and pointers to build a function that returns an array
	const double odds2 = 1/36.0;
	const double odds3 = 2/36.0;
	const double odds4 = 3/36.0;
	const double odds5 = 4/36.0;
	const double odds6 = 5/36.0;
	const double odds7 = 6/36.0;
	const double odds8 = 5/36.0;
	const double odds9 = 4/36.0;
	const double odds10 = 3/36.0;
	const double odds11 = 2/36.0;
	const double odds12 = 1/36.0;
	
	double odds[arraySize] = {odds2, odds3, odds4, odds5, odds6, odds7, odds8, odds9, odds10, odds11, odds12};
	
	// the following loop scales the odds expected values according to the number of trials
	for(int i = 0; i < arraySize; i++)
		odds[i] *= numberOfTrials;
		
	// int test[arraySize] = {0, 1, 1, 7, 6, 5, 2, 9, 6, 0, 0};
		
	cout << "Sum\t#Rolled\t   Odds\t\t%Error\n";
	
	for(int i = 0; i < arraySize; i++){
		cout << (i + 2) << "\t   " << dieTotalsCount[i] << "\t   " 
			 << odds[i] << "\t" << calculateError(dieTotalsCount[i], odds[i]) << endl;
	}
}

double calculateError(int numberRolled, int odds){
	return fabs(100.00 * ((numberRolled - odds)/static_cast<double>(odds))); // casting odds to double to avoid integer division
}

void setToZero(int dieTotalsCount[], int arraySize){
	
	for(int i = 0; i < arraySize; i++)
		dieTotalsCount[i] = 0;
}



