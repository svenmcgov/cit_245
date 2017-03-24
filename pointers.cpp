#include <iostream>
using namespace std;

void swap(int a, int b){
	int temp = a;
	a = b;
	b = temp;
}

// swap by reference
void swapr(int &a, int &b)
{
	int temp = a;
	a = b;
	b = temp;
}

// swap by pointers
void swapp(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
int main(){
	int x = 3;

	// declare a pointer put the address of x into it
	int *y = &x;
	
	// share memory with x.  z will have the same memory location as x
	int &z = x;
	
	int p = 1, q = 2;
	cout << "x = " << x << endl;
	cout << "&x = " << &x << endl;
	cout << "y = " << y << endl;
	cout << "*y = " << *y << endl;
	cout << "z = " << z << endl;
	x = 7;
	cout << "z = " << z << endl;
	cout << "p = " << p << " ";
	cout << "q = " << q << endl;

	// pass by value no swap should occur
	swap(p,q);
	cout << "p = " << p << " ";
	cout << "q = " << q << endl;
	// swap by reference
	swapr(p,q);
	cout << "p = " << p << " ";
	cout << "q = " << q << endl;
	// swap by pointers.
	swapp(&p,&q);
	cout << "p = " << p << " ";
	cout << "q = " << q << endl;
}
