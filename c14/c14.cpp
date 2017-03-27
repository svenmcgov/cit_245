// Stephen McGovern CIT-245
// 3/23/17
#include <iostream>
#include <string>
using namespace std;

class Gun{

	public:
		Gun( );
		Gun(string theManufacturer, string theCaliber);
		string getManufacturer( ){return manufacturer;};
		string getCaliber( ){return caliber;};
		void setManufacturer(string theManufacturer){manufacturer = theManufacturer;}
		void setCaliber(string theCaliber){caliber = theCaliber;}
		string toString( );
	protected:
		string manufacturer;
		string caliber;
};

// ------------------ begin class Gun definition -----------------------------
Gun::Gun( ) : manufacturer("gun"), caliber("high caliber")
{ /* defaults for no arg are "gun" and "high caliber" */}

Gun::Gun(string theManufacturer, string theCaliber) :
   manufacturer(theManufacturer), caliber(theCaliber)
{ /* intentionally blank */ }

string Gun::toString( ){
   return manufacturer + " " + caliber;
}
// ---------------------------------------------------------------------------

class Handgun: public Gun{
	
	public:
		Handgun( );
		Handgun(string theManufacturer, string theCaliber, 
		        string theGrips, string theSights, bool hasLaser);
		bool hasLaser( ){return laser;};
		string toString( );
	protected:
		string grips;
		string sights;
		bool laser;		
};

// ------------------ begin class Handgun definition--------------------------
Handgun::Handgun( ): grips("basic grips"), sights("basic sights"), laser(false)
{ /* super class no arg constructor called automatically */}

Handgun::Handgun(string theManufacturer, string theCaliber, 
		         string theGrips, string theSights, bool hasLaser) :
   Gun(theManufacturer, theCaliber), grips(theGrips), sights(theSights), laser(hasLaser)
{ /* left blank intentionally */ }

string Handgun::toString( ){
   string laserStatus;
   if(hasLaser())
      laserStatus = "and it has a laser.";
   else
      laserStatus = "and it does not have a laser.";
      
   return manufacturer + " " + caliber + " " + grips + " " + sights + "\n" +
          laserStatus;
}
// ---------------------------------------------------------------------------

class Revolver: public Handgun{
	
	public:
		Revolver( );
		Revolver(string theManufacturer, string theCaliber, 
      		     string theGrips, string theSights, bool isLaser,
      		     bool isSingleAction, int theNumberOfRounds);
      	string toString( );
	private:
		bool singleAction;
		int numberOfRounds;
};

// ------------------ begin class Revolver definition--------------------------
Revolver::Revolver( ) : singleAction(true), numberOfRounds(6)
{ /* left blank intentionally */ }

Revolver::Revolver(string theManufacturer, string theCaliber, 
      		       string theGrips, string theSights, bool isLaser,
      		       bool isSingleAction, int theNumberOfRounds)
   : Handgun(theManufacturer, theCaliber, theGrips, theSights, isLaser),
     singleAction(isSingleAction), numberOfRounds(theNumberOfRounds)
{ /* left blank intentionally */ }

string Revolver::toString( ){
   string laserStatus;
   if(laser)
      laserStatus = "laser";
   else
      laserStatus = "no laser";
      
   string singleActionStatus;
   if(singleAction)
      singleActionStatus = "single action";
   else
      singleActionStatus = "double action";
   // used protected variables in ancestor, didn't need getter/setter   
   return manufacturer + ", " + caliber + ", " + to_string(numberOfRounds) + " shots, " + 
          singleActionStatus + ", " + grips + ", " + laserStatus + ", " + sights;
}
// ---------------------------------------------------------------------------

class Pistol: public Handgun{
	public:
		Pistol( );
		Pistol(string theManufacturer, string theCaliber, 
      		   string theGrips, string theSights, bool isLaser, bool isSemiauto);
		string toString( );
	private:
		bool semiauto;
};

// ------------------ begin class Revolver definition--------------------------
Pistol::Pistol( ) : semiauto(true)
{ /* left blank intentionally */ }

Pistol::Pistol(string theManufacturer, string theCaliber, 
      		   string theGrips, string theSights, bool isLaser, bool isSemiauto)
   : Handgun(theManufacturer, theCaliber, theGrips, theSights, isLaser), semiauto(isSemiauto)
{ /* left blank intentionally */ }

string Pistol::toString( ){
   string laserStatus;
   if(laser)
      laserStatus = "laser";
   else
      laserStatus = "no laser";
   string semiautoStatus;
   if(semiauto)
      semiautoStatus = "semi-auto";
   else
      semiautoStatus = "not semi-auto";
   // used protected variables in ancestor, didn't need getter/setter      
   return manufacturer + ", " + caliber + ", " + semiautoStatus  + ", " + 
          grips + ", " + laserStatus + ", " + sights;
}
// ----------------------------------------------------------------------------
int main( ){
   /*
   // testing
   Gun gun1("Glock","9mm");
   Handgun gun2;
   cout << gun2.toString( ) << endl;
   */
   
   Revolver gun1("Smith & Wesson", "0.357", "hoague grips", "Trijicon", true, false, 6);
   cout << "Revolver: " << gun1.toString( ) << endl;
   
   Pistol gun2("Glock", "9mm", "manufacturers grips", "3 dot sights", false, true);
   cout << "Pistol: " << gun2.toString( ) << endl;
   return 0;
}



