// Stephen McGovern CIT-245
// 2/18/17
#include <iostream>
#include <string>
using namespace std;

class Location{
	public:
		void setLocation(int longitude, int latitude);
		int getLongitude();
		int getLatitude();
	private:
		int x;
		int y;
};

class Player{
	public:
		void display();
		void displayInventory();
		void setName(string newName);
		string getName();
		void setPassword(string newPass);
		string getPassword();
		void setXP(int newXP);
		int getXP();
		void setLocation(int longitude, int latitude);
		string* getInv();
		void setInv(string newInv[], int size);
	private:
		string name;
		string password;
		int xp;
		Location loc;
		string inventory[4];
};

int main(){
	string inv1[] = {"short sword", "long bow", "rope", "quiver"};
	string inv2[] = {"Sting", "Phial of Galadriel", "cloak", "one ring..."};
	string inv3[] = {"Lyre", "arcane books", "sword", "hooded cloak"};
	
	Player aedros, frodo, kvothe;
	aedros.setName("Aedros");
	aedros.setPassword("777777");
	aedros.setXP(50);
	aedros.setLocation(125264, 95432);
	aedros.setInv(inv1, 4);
	
	frodo.setName("Frodo");
	frodo.setPassword("gandalf_rules");
	frodo.setXP(7000);
	frodo.setLocation(47567, 66503);
	frodo.setInv(inv2, 4);
	
	kvothe.setName("Kvothe pronounced 'Quothe'");
	kvothe.setPassword("ademre");
	kvothe.setXP(500);
	kvothe.setLocation(4530, 345356);
	kvothe.setInv(inv3, 4);
	
	cout << "\nThis program generates three player objects and displays them.\n\n";
	
	aedros.display();
	frodo.display();
	kvothe.display();
	
}

void Player::display(){
	cout << "Player Info - " << endl
		 << "Name:\t\t" << getName() << endl
		 << "Password:\t" << getPassword() << endl
		 << "Experience:\t" << getXP() << endl
		 << "Position:\t" << loc.getLongitude() << ", " << loc.getLatitude() << endl
		 << "Inventory:\t" << endl;
	
	displayInventory();
}

void Player::displayInventory(){
	for(int i = 0; i < 4; i++)
		cout << "\t" << inventory[i] << endl;
	cout << endl << endl;
}

void Location::setLocation(int longitude, int latitude){
	x = longitude;
	y = latitude;
}

int Location::getLongitude(){return x;}
int Location::getLatitude(){return y;}

void Player::setName(string newName){
	name = newName;
}

string Player::getName(){return name;}

void Player::setPassword(string newPass){
	password = newPass;
}

string Player::getPassword(){return password;}

void Player::setXP(int newXP){
	xp = newXP;
}

int Player::getXP(){return xp;}

void Player::setLocation(int longitude, int latitude){
	loc.setLocation(longitude, latitude);
}

string* Player::getInv(){return inventory;} 

void Player::setInv(string newInv[], int size){
	for(int i = 0; i < size; i++){
		inventory[i] = newInv[i];
	}
}


