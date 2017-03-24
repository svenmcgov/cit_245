// Stephen McGovern - CIT 245
// 02/16/17

#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int getRandomInt(int min, int max);
// min and max are the lower and upper bounds for the range
// returns a random int between given min and max

void fillArray(int a[], int b[], int size);
// a is an array  and size is the number of elements in contains
// will fill the array a
// b array will be passed to countTrack

void printArray(int a[], int size);
// a is an array and size is the number of elements in contains
// will print an array

void countTrack(int counts[], int a);
// a is a random int that will be checked
// function will increment counts 

void printCounts(int a[], int size);

bool continuePrompt();

int main(){
	do{
		srand(time(NULL));
		const int SIZE_RAND = 20;
		const int SIZE_COUNTS = 10;
		int randomArray[20];
		int numberCounts[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
		
		cout << "\nThis program generates random numbers and tabulates the results.\n\n";
		fillArray(randomArray, numberCounts, SIZE_RAND);
		cout << "The numbers generated are:\n";
		printArray(randomArray, SIZE_RAND);
		cout << endl;
		cout << "The numbers sorted are:\n";
		sort(randomArray, randomArray + 20);
		printArray(randomArray, SIZE_RAND);
	
		printCounts(numberCounts, SIZE_COUNTS);
	}while(continuePrompt());
}

int getRandomInt(int min, int max){
	return min + (rand() % (max - min + 1));
}

void fillArray(int a[], int b[], int size){
	// note size is for a[], NOT b[].
	for(int i = 0; i < size; i++){
		a[i] = getRandomInt(1, 10);
		countTrack(b, a[i]);
	}
}

void printArray(int a[], int size){
	for(int i = 0; i < size; i++){
		cout << a[i] << " ";
	}
	cout << endl << endl;
}

void countTrack(int counts[], int a){

	// note the index will be one less.
	switch(a){
		case 1:
			counts[0]++;
			break;
		case 2:
			counts[1]++;
			break;
		case 3:
			counts[2]++;
			break;
		case 4:
			counts[3]++;
			break;
		case 5:
			counts[4]++;
			break;
		case 6:
			counts[5]++;
			break;
		case 7:
			counts[6]++;
			break;
		case 8:
			counts[7]++;
			break;
		case 9:
			counts[8]++;
			break;
		case 10:
			counts[9]++;
			break;
		default:
			cout << "Warning: Number not expected.  Check random generator range.";
	}

}

void printCounts(int a[], int size){
	// need the 'i + 1' to line up with the counts,
	// count for 1 is stored in index 0.
	cout <<  "Number Counts\n";
	for(int i = 0; i < size; i++){
		if(i < 9){
			cout << " " << i + 1 << ": " << a[i] << endl;
		}else{
			cout << i + 1 << ": " << a[i] << endl;
		}
	}
	cout << endl;
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



