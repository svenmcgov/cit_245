// Stephen McGovern CIT-245
// 3/8/17

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void writeToFile(ostream& outFile);
// takes a reference to an output stream
// prompts user for a phrase and adds phrase to file

int main(){
	
	ifstream fin;
	ofstream fout;
	fstream finout;
	
	fin.open("advice.txt");
	
	if(!fin.fail()){ //file exists
		cout << "Found Advice File.\nOld Advice:" << endl;
		
		char next;
		fin.get(next);
		while(!fin.eof()){
			cout << next;
			fin.get(next);
		}
		
		fin.close(); // close file input stream
		
		fout.open("advice.txt", ios::app);
		writeToFile(fout);
		
		fout.close(); // close file output stream
		
	}else{
		cout << "Could not open Advice File.\nAssumption: first run - creating a new file..." << endl;
		fin.close();
		finout.open("advice.txt", ios::in | ios::out | ios::trunc);
		writeToFile(finout);
		
		finout.close(); // close
	}
	
	
	
	cout << endl;
}

void writeToFile(ostream& outFile){
	cout << "Enter a phrase for the next user:" << endl;
	
	string userInput = "";
	getline(cin, userInput);
	
	outFile << userInput << endl;
}
