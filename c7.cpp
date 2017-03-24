// Stephen McGovern - CIT-245
// 02/25/17

#include <iostream>
#include <string>
using namespace std;

class CounterType
{
	public:
		CounterType();
		CounterType(int count, string countName);
		void setCount(int count);
		int getCount();
		static int getDelta();
		void inc(int times); // increase count by number of 'times'
		void dec(int times); // decrease count by number of 'times'
		void display();
	private:
		static int delta; // delta is the count of changes (inc's and dec's)
		int count;
		string countName;
		string creationNote;
};

int CounterType::delta = 0;

int main(){

	/*
	cout << "This program tests the CounterType class.\n";
	CounterType count1, count2, count3, count4;
	count1.setCount(7);
	count2.setCount(11);
	count3.setCount(13);
	count4.setCount(17);
	
	
	cout << "The first count is:  " << count1.getCount() << endl
		 << "The second count is: " << count2.getCount() << endl
		 << "The third count is:  " << count3.getCount() << endl
		 << "The fourth count is: " << count4.getCount() << endl;
	*/
	
	CounterType c1;
	CounterType c2(200, "C2");
	
	cout << endl;
	c1.display();
	cout << endl;
	c2.display();
	
	c1.inc(85);
	cout << endl;
	c1.display();
	c2.dec(242);
	cout << endl;
	c2.display();
	cout << endl;
	
	return 0;
	
}

CounterType::CounterType()
	: count(0), countName("C1"), creationNote("(created with the default constructor)"){
	/* Body intentionally empty */
}

CounterType::CounterType(int count, string countName){
	this->count = count;
	this->countName = countName;
	creationNote = "(created as c2(200))";
}

void CounterType::setCount(int count){this->count = count;}
int CounterType::getCount(){return count;}
int CounterType::getDelta(){return delta;}

void CounterType::inc(int times){
	
	for(int i = 0; i < times; i++){
		count++;
		delta++;
	}
}

void CounterType::dec(int times){
	
	for(int i = 0; i < times; i++){
		count--;
		delta++;
	}
}

void CounterType::display(){
	if (delta > 0)
		creationNote = ""; // nix creation note if this isn't the first display
		
	cout << "Current state of " << countName << " " << creationNote << endl
	     << "Current count: " << getCount() << endl
	     << "Total increments and decrements: " << getDelta() << endl;

}





