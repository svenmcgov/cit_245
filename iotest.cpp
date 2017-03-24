#include <iostream>
#include <fstream>
using namespace std;

int main(){
	
	ifstream fin;
	fin.open("test.txt");
	
	char next;
	fin.get(next);
	while(!fin.eof()){
		cout << next;
		fin.get(next);
	}
	
	cout << endl;
}
