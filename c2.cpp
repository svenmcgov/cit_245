// Stephen McGovern CIT-245
// 01/04/17

#include <iostream>
#include <cmath>
using namespace std;

int main(){
	
	const double PI = 3.141592;
	const double WATER_WEIGHT = 62.4;  // lbs per cubic foot
	bool continueFlag = true;
	double radius = 0.0;
	double weight = 0.0;
	double buoyantForce = 0.0;
	
	do{
		cout << "This program computes Buoyant Force in water given sphere radius.\nBased on the weight of the sphere,\nit determines whether the sphere floats or sinks.\n";
		cout << "Enter the radius of the sphere. ";
		cin >> radius;
		cout << "You entered " << radius << "\n\n";
		
		cout << "Enter the weight of the sphere. ";
		cin >> weight;
		cout << "You entered " << weight << "\n\n";
		
		buoyantForce = 4.0/3.0 * PI * pow(radius, 3) * WATER_WEIGHT; // ^ and ** don't work, need to import cmath
		cout << "Bouyant Force = " << buoyantForce << "\n";
		
		if(weight >= buoyantForce){
			cout << "The sphere sinks because the Buoyant Force " <<  buoyantForce << " is less than the weight of the sphere " << weight << "\n";
		}else{
			cout << "The sphere floats because the Buoyant Force " << buoyantForce << " is greater than the weight of the sphere " << weight << "\n";
		} // equal exactly case..?  should be submerged but stick towards the top.  making first check >=.
			
		char promptAnswer;
		
		// reusing from assignment c1
		while(continueFlag){
			cout << "Recalculate?  y/n : ";
			cin >> promptAnswer;
			if(promptAnswer == 'y' || promptAnswer == 'Y'){
				break; // return to outer while with continueFlag still set to true
			}else if(promptAnswer == 'n' || promptAnswer == 'N'){
				continueFlag = false; // end the program
			}else{
				cout << "Unable to recognize response.\n"; // ask for y/n again
			}
		}
	
	}while(continueFlag);
	
	return 0;
}
