// Stephen McGovern CIT-245
// 02/08/17

#include <iostream>
using namespace std;

void getInput(int& x, int& y);
// prompt user for numerator and denominator
// sets variables passed to response
void reduce(int& x, int& y, int gcd);
// accepts numerator, denominator, gcd
// divides numerator and denominator by gcd and sets the variables passed
int gcd(int p, int q);
// sets remainder of p divided by q to q
// sets p equal to original q.  continues while q != 0 and returns p (the gcd)
bool continuePrompt();
// prompts to see if user wants to continue
// returns true or false


int main(){
	
	bool continueFlag = true;
	
	while(continueFlag){
		int numerator, denominator, user_gcd;
		getInput(numerator, denominator);
	
		cout << "Your fraction is: " << numerator << "/" << denominator << endl << endl;
	
		user_gcd = gcd(denominator, numerator);
		cout << "The greatest common denominator is: " << user_gcd << endl;
		reduce(numerator, denominator, user_gcd);
	
		cout << "The fraction in lowest terms is: " << numerator << "/" << denominator << endl << endl;
		
		continueFlag = continuePrompt();
	}
}

void getInput(int& x, int& y){
	cout << "Enter the numerator followed by the denominator: ";
	cin >> x >> y;
}

void reduce(int& x, int& y, int gcd){
	x /= gcd;
	y /= gcd;
}

int gcd(int p, int q){
	int temp = 0;
	while (q != 0){
		temp = q;
		q = p % q;
		p = temp;
	}
	return p;
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
