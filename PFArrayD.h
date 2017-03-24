#ifndef PFARRAYD_H
#define PFARRAYD_H

class PFArrayD
{
	public:
		PFArrayD( );
		// initializes with capacity of 50
		
		PFArrayD(int capacity);
		
		PFArrayD(const PFArrayD& pfaObject);
		
		void addElement(double element);
		
		bool full( ) const;
		// returns true if the array is full
		
		int getCapacity( ) const;
		
		int getNumberUsed( ) const;
		void emptyArray( );
		
		double& operator[](int index);
		
		PFArrayD& operator =(const PFArrayD& rightSide);
		
		~PFArrayD( );
		
	protected:
		double *a;
		int capacity;
		int used;
};

#endif


