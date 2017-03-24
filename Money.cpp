#include <string>
using namespace std;
#include "Money.h"

Money::Money()
{
	money = 0;
	moneyString = "Zero dollars.";
}

Money::Money(string moneyInput)
{
	money = 0;  // initialize to zero, will set based on moneyString
	moneyString = moneyInput;

	big[0] = "Hundred";
	big[1] = "Thousand";
	big[2] = "Million";
	big[3] = "Billion";
	
	// remember to offset index by one
	// zero will be special case
	to_19[0] = "One";
	to_19[1] = "Two";
	to_19[2] = "Three";
	to_19[3] = "Four";
	to_19[4] = "Five";
	to_19[5] = "Six";
	to_19[6] = "Seven";
	to_19[7] = "Eight";
	to_19[8] = "Nine";
	to_19[9] = "Nine";
	to_19[10] = "Ten";
	to_19[11] = "Eleven";
	to_19[12] = "Twelve";
	to_19[13] = "Thirteen";
	to_19[14] = "Fourteen";
	to_19[15] = "Fifteen";
	to_19[16] = "Sixteen";
	to_19[17] = "Seventeen";
	to_19[18] = "Eighteen";
	to_19[19] = "Nineteen";
	
	tens[0] = "Ten";
	tens[1] = "Twenty";
	tens[2] = "Thirty";
	tens[3] = "Forty";
	tens[4] = "Fifty";
	tens[5] = "Sixty";
	tens[6] = "Seventy";
	tens[7] = "Eighty";
	tens[8] = "Ninety";
}

string Money::getMoney()
{
	return moneyString;
}

void Money::setMoney(string moneyInput){moneyString = moneyInput;}

void Money::removePunctuation()
{
	string temp = "";
	for(int i = 0; i < moneyString.length(); i++)
	{
		if(moneyString.substr(i,1) == "," || moneyString.substr(i,1) == "."
		      || moneyString.substr(i,1) == "$")
		{
			continue;
		}
		temp += moneyString.substr(i,1);
	}
	
	moneyString = temp;
}

void Money::convertToWord(){
	removePunctuation();
	
	string temp = "";
	
	for(int i = 0; i < moneyString.length(); i++){
		if((moneyString.length() - i) % 6 == 1){
			temp += ones[stoi(moneyString.substr(i, 1)) - 1] + " " + big[2];
			continue;
		}
	
		if((moneyString.length() - i) % 3 == 1){
			temp += ones[stoi(moneyString.substr(i, 1)) - 1] ;
		}
		
		if((moneyString.length() - i) % 4 == 1){
			temp += tens[stoi(moneyString.substr(i, 1))];
		}
		
		if((moneyString.length() - i) % 5 == 1){
		
		}
		
		temp +=
		
	}
	
	moneyString = temp;
}



















