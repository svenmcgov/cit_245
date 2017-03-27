// Created by Stephen McGovern
// CIT-245 03/15/17

#include <iostream>
#include <string>
using namespace std;

void hanoiV1(char start, char temp, char target, int disks);
/* parameters:  -chars for start, temp, and target positions 
                (can be 1, 2, 3 or a, b, c)
                -int for number of disks

   		  req:  a bigger disk can't be on top of a smaller disk.
                you can't move a disk from underneath without moving what
                is on top first.
                
       action:  console output shows the movement of disks from start to target      
*/

int hanoiV2(char start, char temp, char target, int disks, int& count);
/* parameters:  -chars for start, temp, and target positions 
                (can be 1, 2, 3 or a, b, c)
                -int for number of disks
				- *NEW* count is a tracker for number of moves needed to move all
				discs from start to target

   		  req:  a bigger disk can't be on top of a smaller disk.
                you can't move a disk from underneath without moving what
                is on top first.
                
       action:  console output shows the movement of disks from start to target
                and increments pass by reference count variable
       return:  count   
*/


int prompt();
// prompt user for input
// returns input

bool continueCheck();


int main(){
	
	cout << endl;
	
	int input = 0;
	int count = 0; // initialize count to zero
	
	do{
	input = prompt();
	cout << "Start 1, Target 2, Temporary 3.\n";
	// changed 'A', 'B', 'C' to 1, 2, 3 to be consistent with prompt
	cout << "Number of moves: " << hanoiV2('1', '3', '2', input, count) << endl << endl;
	}while(continueCheck());
	
	// hanoiV1('1', '3', '2', input); // testing
}

void hanoiV1(char start, char temp, char target, int disks){
	if(disks ==0){
		cout << "No disks" << endl;
		return;
	}
	
	if(disks == 1){
		cout << "Disk " << disks << " from peg " << start << " to peg " << target << endl;
	}else{
		hanoiV1(start, target, temp, disks - 1);
		cout << "Disk " << disks << " from peg " << start << " to peg " << target << endl;
		hanoiV1(temp, start, target, disks - 1);
	}
}

// returns int count for number of moves on top of printing the moves
int hanoiV2(char start, char temp, char target, int disks, int& count){
	if(disks ==0){
		cout << "No disks" << endl;
		return 0;
	}
	
	count++;
	
	if(disks == 1){
		cout << "Disk " << disks << " from peg " << start << " to peg " << target << endl;
	}else{
		hanoiV2(start, target, temp, disks - 1, count);
		cout << "Disk " << disks << " from peg " << start << " to peg " << target << endl;
		hanoiV2(temp, start, target, disks - 1, count);
	}
	
	return count;
}

int prompt(){
	int input;
	bool inputOK = false; 
	while(!inputOK){
		cout << "Enter the number of disks: ";
		if(!(cin >> input)){
			cin.clear();
			cin.ignore();
			cout << "Invalid input.  Please enter a number." << endl;
			continue;
		}
		inputOK = true;
	}
	
	return input;
}

bool continueCheck(){

	char ans;
	while(true){
		cout << "Continue? y/n\n";
		cin >> ans;
		if(ans == 'y' || ans == 'Y'){
			return true;
		}else if(ans == 'n' || ans == 'N'){
			return false;
		}else{
			cout << "Did not recognize response.\n";
			continue;
		}
	}
}








