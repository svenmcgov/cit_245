// Stephen McGovern CIT-245
// 02/25/17

#include <iostream>
#include <cstdlib>
#include <cmath>
using namespace std;

// starter code from chapter 8, Absolute C++ Sixth Edition
class Money
{
	public:
		Money();
		Money(double amount);
		Money(int theDollars, int theCents);
		Money(int theDollars);
		double getAmount() const;
		int getDollars() const;
		int getCents() const;
		Money percent(double percentDesired);
		
		friend const Money operator +(const Money& amount1,
									  const Money& amount2);
		friend const Money operator -(const Money& amount1,
									  const Money& amount2);
									  
		friend const Money operator -(const Money& amount);
									  
		friend bool operator <(const Money& amount1,
							   const Money& amount2);
		friend bool operator >(const Money& amount1,
							   const Money& amount2);
		friend bool operator ==(const Money& amount1,
  							    const Money& amount2);
  		friend const Money operator %(const Money& amount1,
  							    double percentDesired);
							   
		friend ostream& operator <<(ostream& outputStream,
		 							const Money& amount);
		friend istream& operator >>(istream& inputStream,
									Money& amount);
									
	private:
		int dollars, cents;
		int dollarsPart(double amount) const; // from 7.2
		int centsPart(double amount) const; // from 7.2
		int round(double number) const; // from 7.2
};

int main(){
	Money yourAmount, myAmount(10, 9);
	cout <<  "Enter an amount of money: ";
	cin >> yourAmount;
	cout << "Your amount is " << yourAmount << endl
		 << "My amount is " << myAmount << endl;
		 
	if (yourAmount == myAmount)
		cout << "We have the same amounts.\n";
	else
		cout << "One of us is richer.\n";
	
	if (yourAmount > myAmount)
		cout << "You have more money than me." << endl;
	
	if (yourAmount < myAmount)
		cout <<  "You have less money than me" << endl;
		
	// cout << "10% of your money is: " << yourAmount.percent(.10) << endl;
	
	cout <<  "10% of your money is: " << yourAmount % .10 << endl;
	
	cout << yourAmount << " + " << myAmount << " equals " << yourAmount+myAmount << endl;
	
	cout << yourAmount << " - " << myAmount << " equals " << yourAmount-myAmount << endl;  
	
	return 0;
}

Money::Money(): dollars(0), cents(0)
{/* intentionally blank */}

Money::Money(double amount)
				: dollars(dollarsPart(amount)), cents(centsPart(amount))
{/* intentionally blank */}

Money::Money(int theDollars): dollars(theDollars), cents(0)
{/* intentionally blank */}

Money::Money(int theDollars, int theCents){
	if((theDollars < 0 && theCents > 0) ||
	   (theDollars > 0 && theCents < 0))
	{
		cout << "Inconsistent money data.\n";
		exit(1);
	}
	dollars = theDollars;
	cents = theCents;
}

double Money::getAmount() const{
	return (dollars + cents*0.01);
}

int Money::getDollars() const{
	return dollars;
}

int Money::getCents() const{
	return cents;
}

Money Money::percent(double percentDesired){
	double percentCents = (dollars * 100 + cents) * percentDesired;
	int tempDollars = floor(percentCents) / 100;
	int tempCents = (round(fabs(percentCents))) % 100;

	return (Money(tempDollars, tempCents));
}

int Money::dollarsPart(double amount) const{
	return static_cast<int>(amount);
}

int Money::centsPart(double amount) const{
	double doubleCents = amount * 100;
	int intCents = (round(fabs(doubleCents))) % 100;
	if(amount < 0)
		intCents = -intCents;
	return intCents;
}

int Money::round(double number) const{
	return static_cast<int>(floor(number + 0.5));
}

const Money operator +(const Money& amount1, const Money& amount2){
	int allCents1 = amount1.cents + amount1.dollars*100;
	int allCents2 = amount2.cents + amount2.dollars*100;
	int sumAllCents = allCents1 + allCents2;
	int absAllCents = abs(sumAllCents);
	int finalDollars = absAllCents / 100;
	int finalCents = absAllCents % 100;
	
	if(sumAllCents < 0){
		finalDollars = -finalDollars;
		finalCents = -finalCents;
	}
	
	return Money(finalDollars, finalCents);
}

const Money operator -(const Money& amount1, const Money& amount2){
	int allCents1 = amount1.cents + amount1.dollars*100;
	int allCents2 = amount2.cents + amount2.dollars*100;
	int subtractAllCents = allCents1 - allCents2;
	int absAllCents = abs(subtractAllCents);
	int finalDollars = absAllCents / 100;
	int finalCents = absAllCents % 100;
	
	if(subtractAllCents < 0){
		finalDollars = -finalDollars;
		finalCents = -finalCents;
	}
	
	return Money(finalDollars, finalCents);

}

const Money operator -(const Money& amount){
	return Money(-amount.dollars, -amount.cents);
}

bool operator <(const Money& amount1, const Money& amount2){
	int dollars1 = amount1.getDollars();
	int dollars2 = amount2.getDollars();
	int cents1 = amount1.getCents();
	int cents2 = amount2.getCents();
	return ((dollars1 * 100 + cents1) < (dollars2 * 100 + cents2)); // book does this differently on 367
}																   // sticking with my method

bool operator >(const Money& amount1, const Money& amount2){
	int dollars1 = amount1.getDollars();
	int dollars2 = amount2.getDollars();
	int cents1 = amount1.getCents();
	int cents2 = amount2.getCents();
	return ((dollars1 * 100 + cents1) > (dollars2 * 100 + cents2));
}

bool operator ==(const Money& amount1, const Money& amount2){
	return ((amount1.dollars == amount2.dollars) && (amount1.cents == amount2.cents));
}

const Money operator %(const Money& amount1, double percentDesired){
	
	double percentCents = (amount1.getDollars() * 100 + amount1.getCents()) * percentDesired;
	int tempDollars = floor(percentCents) / 100;
	int tempCents = static_cast<int>((round(fabs(percentCents)))) % 100;
	return (Money(tempDollars, tempCents));
}

ostream& operator <<(ostream& outputStream, const Money& amount){
	int absDollars = abs(amount.dollars);
	int absCents = abs(amount.cents);
	if(amount.dollars < 0 || amount.cents < 0)
		outputStream << "$-";
	else
		outputStream << '$';
	outputStream << absDollars;
	
	if(absCents >= 10)
		outputStream << '.' << absCents;
	else
		outputStream << '.' << '0' << absCents;
		
	return outputStream;
}

istream& operator >> (istream& inputStream, Money& amount){
	char dollarSign;
	inputStream >> dollarSign;
	if(dollarSign != '$'){
		cout << "No dollar sign in Money input.\n";
		exit(1);
	}
	
	double amountAsDouble;
	inputStream >> amountAsDouble;
	amount.dollars = amount.dollarsPart(amountAsDouble);
	amount.cents = amount.centsPart(amountAsDouble);
	
	return inputStream;
}
