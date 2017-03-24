// Created by Stephen McGovern 3/15/17

#include <iostream>
#include <string>
using namespace std;
#include "Money.h"

int main(){
	Money money1("$7,003,123");
	cout << money1.getMoney() << endl;
	
	money1.removePunctuation();
	cout << money1.getMoney() << endl;
	
	money1.convertToWord();
	cout << money1.getMoney() << endl;
}
