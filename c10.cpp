// Stephen McGovern CIT-245
// 03/04/17


#include <iostream>
#include <cstddef>
#include <stdlib.h>
using namespace std;

class WrapArrayDeep{

	public:
		WrapArrayDeep();
		WrapArrayDeep(const char a[], int size);
		WrapArrayDeep(const WrapArrayDeep& wad); // copy constructor
		char* getChars();
		void setChars(const char a[], int size);
		string toString(); 
		WrapArrayDeep& operator = (const WrapArrayDeep& rightSide); // might not be necessary
		~WrapArrayDeep(); // destructor with cout line
	private:
		char *chars;
		int size;
};


class WrapArrayShallow{
	
	public:
		WrapArrayShallow();
		WrapArrayShallow(const char a[], int size);
		WrapArrayShallow(WrapArrayShallow& was); // flawed copy constructor
		char* getChars();
		void setChars(const char a[], int size);
		string toString();
		WrapArrayShallow& operator = (const WrapArrayShallow& rightSide); // might not be necessary
		~WrapArrayShallow(); // destructor with cout line
	private:
		char *chars;
		int size;
};


int main(){
	
	// begin part 1...
	
	cout << "\nThis program section uses three variables,\n"
		 << "i = 7, pi a pointer to i, and ppi a pointer to pi.\n\n";
	
	int i = 7;
	int *pi;
	int **ppi;
	
	pi = &i; // & to determine address of i
	ppi = &pi;
	
	cout << "pi = " << pi << endl;
	cout << "address of pi = " << &pi << endl;
	cout << "dereference of pi = " << *pi << endl;
	cout << "address of i = " << &i << endl << endl;
	
	cout << "ppi = " << ppi << endl;
	cout << "address of ppi = " << &ppi << endl;
	cout << "dereference of ppi = " << *ppi << endl;
	cout << "double dereference of ppi = " << **ppi << endl << endl;
	
	// begin part 2...
	
	char letters[] = {'a','b','c','d','e'};
	WrapArrayDeep wad1(letters, 5);
	WrapArrayDeep wad2(wad1);
	
	cout << "WrapArrayDeep 1:" << endl;
	cout << wad1.toString();
	cout << "WrapArrayDeep 2:" << endl;
	cout << wad2.toString();
	
	char newLetters[] = {'{','|','}','~','>'};
	wad1.setChars(newLetters, 5);
	cout << "After changing the contents of WrapArrayDeep 1, WrapArrayDeep 1 and 2 are:\n";
	cout << wad1.toString();
	cout << wad2.toString();
	
	cout << "\nNow doing the same thing with WrapArrayShallow:\n";
	
	WrapArrayShallow was1(letters, 5);
	WrapArrayShallow was2(was1);
	
	cout << "WrapArrayShallow 1:" << endl;
	cout << was1.toString();
	cout << "WrapArrayShallow 2:" << endl;
	cout << was2.toString();
	
	was1.setChars(newLetters, 5);
	cout << "After changing the contents of WrapArrayShallow 1, WrapArrayShallow 1 and 2 are:\n";
	cout << was1.toString();
	cout << was2.toString();
	cout << endl;
	
}

WrapArrayDeep::WrapArrayDeep(){
	size = 5;
	chars = new char[size];
	for(int i = 0; i < size; i++)
		chars[i] = 'a';
}

WrapArrayDeep::WrapArrayDeep(const char a[], int size){
	this->size = size;
	chars = new char[this->size];
	for(int i = 0; i < this->size; i++)
		chars[i] = a[i];
}

WrapArrayDeep::WrapArrayDeep(const WrapArrayDeep& wad){
	size = wad.size;
	chars = new char[this->size];
	for(int i = 0; i < this->size; i++)
		chars[i] = wad.chars[i];
}

char* WrapArrayDeep::getChars(){
	// don't want to return a reference directly to 'chars' 
	// because it is private.  to keep proper encapsulation, 
	// returning a copy in a totally different memory block, note 'new'
	char* temp = new char[size];
	for(int i = 0; i < size; i++)
		temp[i] = chars[i];
	return temp;
}

// note :: = scope resolution operator
void WrapArrayDeep::setChars(const char a[], int size){
	if(this->size != size){
		cout << "Error:  Incompatible array sizes." << endl;
		exit(1);
	}
	
	for(int i = 0; i < this-> size; i++)
		chars[i] = a[i];	
}

string WrapArrayDeep::toString(){
	string temp;
	for(int i = 0; i < size; i++)
		temp = temp + chars[i] + " ";
	temp = temp + '\n';
	return temp;
}

WrapArrayDeep& WrapArrayDeep::operator =(const WrapArrayDeep& rightSide){
	if(size != rightSide.size){
		delete [] chars;
		chars = new char[rightSide.size];
	}
	
	size = rightSide.size;
	for(int i = 0; i < size; i++)
		chars[i] = rightSide.chars[i];
		
	return *this;
}

WrapArrayDeep::~WrapArrayDeep(){
	cout << "Calling destructor for WrapArrayDeep." << endl;
	delete [] chars;
}

// shallow class
WrapArrayShallow::WrapArrayShallow(){
	size = 5;
	chars = new char[size];
	for(int i = 0; i < size; i++)
		chars[i] = 'a';
}

WrapArrayShallow::WrapArrayShallow(const char a[], int size){
	this->size = size;
	chars = new char[this->size];
	for(int i = 0; i < this->size; i++)
		chars[i] = a[i];
}

WrapArrayShallow::WrapArrayShallow(WrapArrayShallow& was){
	size = was.size;
	chars = was.chars; // this will point to the other objects dynamic array
	                   // circumventing encapsulation 
}

char* WrapArrayShallow::getChars(){
	// see WrapArrayDeep for explanation
	char* temp = new char[size];
	for(int i = 0; i < size; i++)
		temp[i] = chars[i];
	return temp;
}

void WrapArrayShallow::setChars(const char a[], int size){
	if(this->size != size){
		cout << "Error:  Incompatible array sizes." << endl;
		exit(1);
	}
	
	for(int i = 0; i < this-> size; i++)
		chars[i] = a[i];	
}

string WrapArrayShallow::toString(){
	string temp;
	for(int i = 0; i < size; i++)
		temp = temp + chars[i] + " ";
	temp = temp + '\n';
	return temp;
}

WrapArrayShallow& WrapArrayShallow::operator =(const WrapArrayShallow& rightSide){
	if(size != rightSide.size){
		delete [] chars;
		chars = new char[rightSide.size];
	}
	
	size = rightSide.size;
	for(int i = 0; i < size; i++)
		chars[i] = rightSide.chars[i];
		
	return *this;
}

WrapArrayShallow::~WrapArrayShallow(){
	cout << "Calling destructor for WrapArrayShallow." << endl;
	/* 
	   tried nullptr check, didn't work
	   tried null check, didn't work
	   read that if it equals 0 then that can check if the pointer is a null reference
	   had to add this check because of 'double free or corruption'
	*/
	if(*chars == 0){
		cout << "This WrapArrayShallow pointer appears to have been deleted already...\n";
		cout << "Check added because of 'double free or corruption' issue.\n";
	}else{
		delete [] chars;	
	}
}

