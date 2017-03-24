#include <string>
using namespace std;

class Money{
	
	public:
		Money();
		Money(string moneyInput);
		string getMoney();
		void setMoney(string moneyInput);
		void removePunctuation();
		void convertToWord();
	private:
		int money;
		string moneyString;
		string big[4]; // ten power
		string to_19[20];
		string tens[9]; // ten multiple
};
