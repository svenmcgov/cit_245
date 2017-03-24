#include <iostream>
#include <stdlib.h>
using namespace std;
#include "PFArrayD.h"

PFArrayD::PFArrayD( ) : capacity(50), used(0)
{
	a = new double[capacity];
}

PFArrayD::PFArrayD(int size) : capacity(size), used(0)
{
	a = new double[capacity];
}

PFArrayD::PFArrayD(const PFArrayD& pfaObject)
	: capacity(pfaObject.getCapacity()), used(pfaObject.getNumberUsed())
{
	a = new double[capacity];
	for (int i = 0; i < used; i++)
		a[i] = pfaObject.a[i];
}

void PFArrayD::addElement(double element)
{
	if(used >= capacity)
	{
		cout << "Attempt to exceed capacity in PFArrayD.\n";
		exit(0);
	}
	a[used] = element;
	used++;
}

int PFArrayD::getNumberUsed( ) const
{
	return used;
}

int PFArrayD::getCapacity( ) const
{
	return capacity;
}

void PFArrayD::emptyArray( )
{ 
	used = 0;
}

bool PFArrayD::full() const
{
	return (capacity == used);
}

double& PFArrayD::operator[](int index)
{
	if(index >= used)
	{
		cout << "Illegal index in PFArrayD.\n";
		exit(0);
	}
	return a[index];
}

PFArrayD& PFArrayD::operator =(const PFArrayD& rightSide)
{
	if (capacity != rightSide.capacity)
	{
		delete [] a;
		a = new double[rightSide.capacity];
	}
	
	capacity = rightSide.capacity;
	used = rightSide.used;
	for (int i = 0; i < used; i++)
		a[i] = rightSide.a[i];
	
	return *this;
}

PFArrayD::~PFArrayD( )
{
	delete [] a;
}
