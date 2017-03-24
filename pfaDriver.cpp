#include <iostream>
using namespace std;

#include "PFArrayD.h"

void testPFArrayD( );

int main( )
{
	cout << "This program tests the class PFArrayD.\n";
	testPFArrayD( );
}

void testPFArrayD( )
{
		
	int cap;
	cout << "Enter capacity of array.\n";
	cin >> cap;
	PFArrayD temp(cap);
	
	cout << "Enter up to " << cap << " nonnegative numbers\n";
	cout << "Place a negative number at the end.\n";
	
	double next;
	cin >> next;
	
	while ((next >= 0) && (!temp.full()))
	{
		temp.addElement(next);
		cin >> next;
	}
	
	cout << "You entered the following " << temp.getNumberUsed() << " numbers\n";
	int index;
	int count = temp.getNumberUsed();
	for(index = 0; index < count; index++)
		cout << temp[index] << " ";
	cout << endl;
	cout << "(plus a sentinel value.)\n";
}
