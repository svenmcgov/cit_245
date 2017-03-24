#include <iostream>
using namespace std;

int main(){
	
	int j = 10;
	int d = 5;
	double sum = 0;
	
	while(j >=0){
		sum += d;
		-j;
	}

	cout << sum;
	
	return 0;
}
